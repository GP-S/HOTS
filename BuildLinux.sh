#!/bin/bash
#### Import distro specific variables
source /etc/os-release
if [[ "$ID" = "arch" ]]; then
  ID_LIKE="arch"
fi

#### Variables initialisations
debian_packages=("git" "build-essential" "cmake" "python" "libsdl1.2-dev" "libopenal-dev" "libopenal1" "libsdl1.2debian" "python-ply")
suse_packages=("git" "devel_basis" "cmake" "python" "libSDL-devel" "libSDL-1_2-0" "python-ply" "openal-soft" "openal-soft-devel")
rhel_packages=("git" "gcc" "gcc-c++" "make" "cmake" "python" "python-ply" "SDL" "SDL-devel" "openal-soft-devel" "openal-soft")
arch_packages=("git" "base-devel" "cmake" "sdl" "python2" "python2-ply" "openal")
uninstalled=()
SUDO=''
try_install=0

#### Function declaration

function check_for_package {
  case $ID_LIKE in
    suse)
      rpm -q "$@" > /dev/null 2>&1
    ;;
    debian)
      dpkg -s "$@" > /dev/null 2>&1
    ;;
    *rhel*)
      rpm -q "$@" > /dev/null 2>&1
    ;;
    arch)
      pacman -Qs "$@" > /dev/null 2>&1
    ;;
    *)
      false
    ;;
  esac
}

function check_for_command {
  hash "$1" > /dev/null 2>&1
}

function install_package {
 case $ID_LIKE in
    suse)
      $SUDO zypper --non-interactive in "$@"
    ;;
    debian)
      $SUDO apt-get --assume-yes install "$@"
    ;;
    *rhel*)
      $SUDO yum -y install "$@"
    ;;
    arch)
      $SUDO pacman --noconfirm -S "$@"
    ;;
  esac
}

#### Check and install needed packages

if [ $EUID -ne 0 ]; then
  if ! check_for_command sudo; then
    try_install=1;
  else
    SUDO='sudo'
  fi
fi

case $ID_LIKE in
  suse)
    for package in ${suse_packages[@]}; do
      if ! check_for_package $package; then
	uninstalled+=($package)
      fi
    done
  ;;
  debian)
    for package in ${suse_packages[@]}; do
      if ! check_for_package $package; then
	uninstalled+=($package)
      fi
    done
  ;;
  *)
    try_install=1
esac

if [ ${#uninstalled[@]} -ne 0 ]; then
  if [ $try_install -eq 0 ] ; then
    read -p "Do you want this script to try installing missing packages ? [Y/n] " yn
    if [[ $yn == N* ]] || [[ $yn == n* ]]; then
      try_install=1
    fi
  fi
  if [ $try_install -eq 0 ] ; then
    install_package ${uninstalled[@]}
  else
    echo "You need to install these packages in order to continue ${uninstalled[@]}"
    exit 1;
  fi
fi

### Uncomment this to make it clone the repository
#if [[ $1 = --no-download ]]; then
#else
#git clone https://github.com/GP-S/HOTS.git
#cd HOTS
#fi

git submodule update --init --recursive

cd Dependencies/Polycode
./BuildLinux.sh
cd ../..

#### Build HOTS
mkdir Build
cd Build
cmake ..
make
make install