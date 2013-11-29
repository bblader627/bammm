#
#makefile for Game
#

RM = rm -f
SRCPATH = .
SRC = Actors/Actor.cpp Actors/ActorInfo.cpp \
Controllers/AiController.cpp Controllers/Controller.cpp Controllers/PlayerController.cpp \
States/BrawlState.cpp States/DrinkState.cpp States/MoveState.cpp \
States/IdleState.cpp Interfaces/IStateCallback.cpp States/MineState.cpp States/CombatState.cpp \
States/SingState.cpp States/SleepState.cpp States/State.cpp States/StateMachine.cpp \
States/DamageState.cpp \
\
Resources/DynamicArray.h Resources/HashMap.h Resources/HashNode.h \
Resources/Heap.h Resources/Queue.h Resources/Stack.h \
\
Weapons/IWeaponType.h Weapons/WeaponData.cpp Weapons/MeleeWeapon.cpp \
Weapons/MeleeCombat.cpp \
\
SceneManager/Vector3D.cpp SceneManager/Grid3D.h SceneManager/SceneManager.cpp  \
Factories/Factory.cpp \
Interfaces/ITickable.cpp \
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
