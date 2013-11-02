#
#makefile for Game
#

RM = rm -f
SRCPATH = .
SRC = actors/actor.h  actors/DwarfActor.h actors/OrcActor.h  \
controllers/AiController.h controllers/Controller.h \
controllers/PlayerController.h states/BrawlState.h states/DrinkState.h \
states/IdleState.h states/IStateCallback.h states/MineState.h \
states/SingState.h states/SleepState.h states/state.h states/statemachine.h \
resources/dynamicarray.h resources/hashmap.h resources/hashnode.h \
resources/heap.h resources/queue.h resources/stack.h resources/vector3d.h \
weapons/IWeaponType.h weapons/weapondata.h weapons/MeleeWeapon.h weapons/Stein.h weapons/OrcishBlade.h \
weapons/MeleeCombat.h states/CombatState.h resources/grid3d.h
TESTNAME = test
TESTSRC = main.cpp
#
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

test: $(TESTSRC)
	g++ $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME)
