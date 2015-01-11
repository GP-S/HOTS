#####################################################################################
#         _____                                   _____              _____          #
#        /\    \             _______             /\    \            /\    \         #
#       /::\____\           /::\    \           /::\    \          /::\    \        #
#      /:::/    /          /::::\    \          \:::\    \        /::::\    \       #
#     /:::/    /          /::::::\    \          \:::\    \      /::::::\    \      #
#    /:::/    /          /::::::::\    \          \:::\    \    /:::/\:::\    \     #
#   /:::/____/          /:::/~~\:::\    \          \:::\    \  /:::/__\:::\    \    #
#  /::::\    \         /:::/    \:::\    \         /::::\    \ \:::\   \:::\    \   #
# /::::::\    \   ____/:::/    / \:::\    \       /::::::\    \_\:::\   \:::\    \  #
#/:::/\:::\    \ /\    \:/____/   \:::\____\     /:::/\:::\    \ \:::\   \:::\    \ #
#:::/  \:::\    /::\____\    |     |:::|    |   /:::/  \:::\____\ \:::\   \:::\____\#
#::/    \:::\  /:::/    /____|     |:::|    |  /:::/    \::/    /  \:::\   \::/    /#
#\/____/ \:::\/:::/    /:\    \   /:::/    /  /:::/    / \/____/\   \:::\   \/____/ #
#         \::::::/    /\::\    \ /:::/    /  /:::/    /      \:::\   \:::\    \     #
#          \::::/    / \:::\    /:::/    /  /:::/    /        \:::\   \:::\____\    #
#          /:::/    /   \:::\__/:::/    /  /:::/    /          \:::\  /:::/    /    #
#         /:::/    /     \::::::::/    /  /:::/    /            \:::\/:::/    /     #
#        /:::/    /       \::::::/    /   \::/    /              \::::::/    /      #
#       /:::/    /         \::::/    /     \/____/                \::::/    /       #
#       \::/    /           \::/____/                              \::/    /        #
#        \/____/             ~~                                     \/____/         #
#                                                                                   #
#####################################################################################
############################# CONTENTS OF THIS FILE #################################
#####################################################################################
#                                                                                   #
#  * General information                                                            #
#  * Copyright and licensing information                                            #
#  * Installation instructions                                                      #
#  * Configuration                                                                  #
#  * FAQ                                                                            #
#  * BUGS                                                                           #
#  * File manifest                                                                  #
#  * Credits                                                                        #
#                                                                                   #
#####################################################################################
############################## General information ##################################
#####################################################################################
#                                                                                   #
#  HOTS is a game developed by engineering students from the graduate school ENSEA. #
#                                                                                   #
#  This game was developed as a part of programming project in our last year of     #
#  ENSEA.                                                                           #
#                                                                                   #
#  Polycode is completely free and open source (MIT license), with all developments #
#  happening publicly on Github. Its core is written in C++ and currently runs on   #
#  Mac, Windows and Linux. iOS and Android support will be planned in the future.   #
#                                                                                   #
#                                                                                   #
#####################################################################################
##################### Copyright and licensing information ###########################
#####################################################################################
#                                                                                   #
#          1) Polycode Licence                                                      #
#                                                                                   #
#     Copyright (C) 2014 by Ivan Safrin, Polycode Team                              #
#                                                                                   #
#     Permission is hereby granted, free of charge, to any person obtaining a copy  #
#  of this software and associated documentation files (the "Software"), to deal    #
#  in the Software without restriction, including without limitation the rights     #
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell        #
#  copies of the Software, and to permit persons to whom the Software is            #
#  furnished to do so, subject to the following conditions:                         #
#                                                                                   #
#     The above copyright notice and this permission notice shall be included in    #
#  all copies or substantial portions of the Software.                              #
#                                                                                   #
#     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    #
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,         #
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE      #
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER           #
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,    #
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN        #
#  THE SOFTWARE.                                                                    #
#                                                                                   #
#          2)                                                                       #
#                                                                                   #
#                                                                                   #
#                                                                                   #
#                                                                                   #
#####################################################################################
########################## Installation instructions ################################
#####################################################################################
#                                                                                   #
#    1) Open a terminal and go into the main repertory named "HOTS"                 #
#                                                                                   #
#    2) Enter the following instructions:                                           #
#                     ./BuildLinux.sh                                               #
#                                                                                   #
#    3) Then you can execute our game with the next instruction:                    #
#                    ./Release/HOTS argument(see the next point)                    #
#                                                                                   #
#    4) There is an unremovable argument. You can find below the list of all the    #
#       arguments you can add to the instruction:                                   #
#          --single: Play a single player game against an AI                        #
#          --server: Play a two  players game as the host                           #
#          --c <serverAddress>: Play a two players game as a client to the given    #
#                               server                                              #
#                                                                                   #
#####################################################################################
###################################### NEWS #########################################
#####################################################################################
#                                                                                   #
#  version alpha 0.1:                                                               #
#     Base of the game:                                                             #
#           -IHM creation                                                           #
#           -GameEngine creation                                                    #
#           -Board creation                                                         #
#           -Card creation.      Card,Hero and spell avalable                       #
#           -IA creation.        Basic IA                                           #
#           -Test creation.      Board,Card,CreationDeck and Effect tests           #
#           -Effect creation.    Bases effect                                       #
#           -utils creation.                                                        #
#                                                                                   #
#####################################################################################
###################################### FAQ ##########################################
#####################################################################################
#                                                                                   #
#  We haven't deploy the game yet, so we haven't usual question from yours clients  #
#                                                                                   #
#####################################################################################
###################################### BUGS #########################################
#####################################################################################
#                                                                                   #
#  None as we know yet.                                                             #
#                                                                                   #
#                                                                                   #
#                                                                                   #
#                                                                                   #
#                                                                                   #
#                                                                                   #
#####################################################################################
############################### File manifest #######################################
#####################################################################################
#                                                                                   #
#  HOTS                                                                             #
#  |____Board                                                                       #
#  |    |____Board.cpp                                                              #
#  |    |____Board.h                                                                #
#  |    |____iBoard.h                                                               #
#  |                                                                                #
#  |                                                                                #
#  |____Card                                                                        #
#  |    |____Beast.cpp                                                              #
#  |    |____Beast.h                                                                #
#  |    |____Capacity.cpp                                                           #
#  |    |____Capacity.h                                                             #
#  |    |____Card.cpp                                                               #
#  |    |____Card.h                                                                 #
#  |    |____Creature.cpp                                                           #
#  |    |____Creature.h                                                             #
#  |    |____Hero.cpp                                                               #
#  |    |____Hero.h                                                                 #
#  |    |____iBeast.h                                                               #
#  |    |____iCapacity.h                                                            #
#  |    |____iCard.h                                                                #
#  |    |____iCreature.h                                                            #
#  |    |____iHero.h                                                                #
#  |    |____Spell.cpp                                                              #
#  |    |____Spell.h                                                                #
#  |                                                                                #
#  |                                                                                #
#  |____Dependencies                                                                #
#  |    |____Polycode                                                               #
#  |         |                                                                      #
#  |                                                                                #
#  |                                                                                #
#  |____Effect                                                                      #
#  |    |____Effect.cpp                                                             #
#  |    |____Effect.h                                                               #
#  |                                                                                #
#  |                                                                                #
#  |_____GameEngine                                                                 #
#  |     |____GameEngine.cpp                                                        #
#  |     |____GameEngine.h                                                          #
#  |     |____GameSimulator.cpp                                                     #
#  |     |____GameSimulator.h                                                       #
#  |     |____iGameSimulator.h                                                      #
#  |     |____iGameSolver.h                                                         #
#  |     |____iSimulatorFactory.h                                                   #
#  |     |____match.h                                                               #
#  |                                                                                #
#  |                                                                                #
#  |_____IA                                                                         #
#  |     |____Agent.cpp                                                             #
#  |     |____Agen.h                                                                #
#  |     |____Hal.cpp                                                               #
#  |     |____Hal.h                                                                 #
#  |     |____IAStruct.inc                                                          #
#  |     |____NeuralNetwork.cpp                                                     #
#  |     |____NeuralNetwork.h                                                       #
#  |     |____NeurMono.cpp                                                          #
#  |     |____NeurMono.h                                                            #
#  |     |____Neurone.cpp                                                           #
#  |     |____Neurone.h                                                             #
#  |     |____StupideAgent.cpp                                                      #
#  |     |____StupideAgent.h                                                        #
#  |                                                                                #
#  |                                                                                #
#  |_____IHM                                                                        #
#  |     |____PolycodeGUI                                                           #
#  |     |    |____board.cpp                                                        #
#  |     |    |____board.h                                                          #
#  |     |    |____card.cpp                                                         #
#  |     |    |____card.h                                                           #
#  |     |    |____IHM.cpp                                                          #
#  |     |    |____IHM.h                                                            #
#  |     |                                                                          #
#  |     |____iboard.h                                                              #
#  |     |____icard.h                                                               #
#  |     |____iihm.h                                                                #
#  |                                                                                #
#  |                                                                                #
#  |_____Network                                                                    #
#  |     |____gameclient.cpp                                                        #
#  |     |____gameclient.h                                                          #
#  |                                                                                #
#  |                                                                                #
#  |_____Test                                                                       #
#  |     |____Board                                                                 #
#  |     |    |____Board_Test.cpp                                                   #
#  |     |    |____Board_Test.h                                                     #
#  |     |    |____CMakeLists.txt                                                   #
#  |     |                                                                          #
#  |     |____Card                                                                  #
#  |     |    |____Card_Test.cpp                                                    #
#  |     |    |____Card_Test.h                                                      #
#  |     |    |____CMakeLists.txt                                                   #
#  |     |                                                                          #
#  |     |____CreateDeck                                                            #
#  |     |    |____CMakeLists.txt                                                   #
#  |     |    |____CreateDeck_Test.cpp                                              #
#  |     |    |____CreateDeck_Test.h                                                #
#  |     |                                                                          #
#  |     |____Board                                                                 #
#  |     |    |____CMakeLists.txt                                                   #
#  |     |    |____Effect_Test.cpp                                                  #
#  |     |    |____Effect_Test.h                                                    #
#  |     |                                                                          #
#  |     |____README.txt                                                            #
#  |                                                                                #
#  |                                                                                #
#  |_____utils                                                                      #
#  |     |____Card types                                                            #
#  |     |____CreateDeck.cpp                                                        #
#  |     |____CreateDeck.h                                                          #
#  |     |____Effect Affinities                                                     #
#  |     |____Effect types                                                          #
#  |     |____file_manager.cpp                                                      #
#  |     |____file_manager.h                                                        #
#  |     |____requesType.inc                                                        #
#  |     |____usefulStruc.inc                                                       #
#  |                                                                                #
#  |                                                                                #
#  |____Release                                                                     #
#  |    |____Ressources                                                             #
#  |    |____UIThemes.pak                                                           #
#  |                                                                                #
#  |                                                                                #
#  |                                                                                #
#  |_____.gitattributes                                                             #
#  |_____.gitignore                                                                 #
#  |_____.gitmodules                                                                #
#  |_____BuildLinux.sh                                                              #
#  |_____CMakeLists.txt                                                             #
#  |_____HOTS.cpp                                                                   #
#  |_____README.txt                                                                 #
#                                                                                   #
#####################################################################################
################################## Credits ##########################################
#####################################################################################
#                                                                                   #
# Programmer:      Nicolas Belouin                                                  #
#                  Thibault Cattelani                                               #
#                  François Denquin                                                 #
#                  Nicolas Léger                                                    #
#                  Armand Verstraete                                                #
#                                                                                   #
# Graphic artist:                                                                   #
#                  Valérie Bousquié                                                 #
#                                                                                   #
#####################################################################################
