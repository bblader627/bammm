#
#makefile for Game
#

RM = rm -f
SRCPATH = .
SRC = Actors/Actor.h Actors/Actor.cpp Actors/ActorInfo.h Actors/ActorInfo.cpp \
Controllers/AiController.h Controllers/Controller.h Controllers/PlayerController.h \
Controllers/AiController.cpp Controllers/PlayerController.cpp \
\
States/BrawlState.h States/DrinkState.h States/MovementState.h \
States/IdleState.h Interfaces/IStateCallback.h States/MineState.h States/CombatState.h \
States/SingState.h States/SleepState.h States/State.h States/StateMachine.h \
States/BrawlState.cpp States/DrinkState.cpp States/MovementState.cpp \
States/IdleState.cpp Interfaces/IStateCallback.cpp States/MineState.cpp States/CombatState.cpp \
States/SingState.cpp States/SleepState.cpp States/State.cpp States/StateMachine.cpp \
\
Resources/DynamicArray.h Resources/HashMap.h Resources/HashNode.h \
Resources/Heap.h Resources/Queue.h Resources/Stack.h SceneManager/Vector3D.h \
\
Weapons/IWeaponType.h Weapons/WeaponData.h Weapons/MeleeWeapon.h \
Weapons/MeleeCombat.h Weapons/MeleeCombat.cpp \
\
SceneManager/Grid3D.h SceneManager/SceneManager.h \
SceneManager/SceneManager.cpp  \
\
Interfaces/ITickable.h Factories/Factory.h Factories/Factory.cpp \
\
JSON/JSON.cpp JSON/JSONParser.cpp JSON/JSONArray.cpp \
JSON/JSONPrimitive.cpp \
\
TestSuite/Time.cpp
TESTNAME = test
TESTSRC = Main.cpp

all: re $(SRC) $(TESTSRC)
	g++ $(SRC) $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME)

debug: re $(SRC) $(TESTSRC)
	g++ $(SRC) $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME) -g

retest: re test

clean:
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) *.gch

fclean: clean
	-$(RM) $(TESTNAME)

re: fclean

test: fclean $(TESTSRC)
	g++ $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME)
