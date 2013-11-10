#
#makefile for Game
#

RM = rm -f
SRCPATH = .
SRC = Actors/Actor.h  Actors/DwarfActor.h Actors/OrcActor.h  \
Controllers/AiController.h Controllers/Controller.h \
Controllers/PlayerController.h States/BrawlState.h States/DrinkState.h \
States/IdleState.h States/IStateCallback.h States/MineState.h \
States/SingState.h States/SleepState.h States/State.h States/StateMachine.h \
Resources/DynamicArray.h Resources/HashMap.h Resources/HashNode.h \
Resources/Heap.h Resources/Queue.h Resources/Stack.h SceneManager/Vector3D.h \
Weapons/IWeaponType.h Weapons/WeaponData.h Weapons/MeleeWeapon.h Weapons/Stein.h \
Weapons/OrcishBlade.h Weapons/MeleeCombat.h States/CombatState.h SceneManager/Grid3D.h \
Actors/OrcActor.h TestSuite/Time.cpp SceneManager/SceneManager.h
TESTNAME = test
TESTSRC = Main.cpp

all: re $(SRC) $(TESTSRC)
	g++ $(SRC) $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME)

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
