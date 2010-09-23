
/*
	Created @ 15.10.2009 by TheFox@fox21.at
	Copyright (c) 2009 TheFox@fox21.at
	
	This file is part of SmileOS.
	
	SmileOS is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	SmileOS is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with SmileOS.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SMILEOS_IDT_H_
#define _SMILEOS_IDT_H_

#include "system.h"


#define IDT_ENTRIES 256

#define PIC1 0x20
#define PIC2 0xa0

#define PIC_EOI 0x20

#define PIC_IRQ0 0x20
#define PIC_IRQ8 0x28

#define PIC_ICW1 0x11
#define PIC_ICW4 0x01


typedef struct{
    unsigned short baseLo;
    unsigned short kseg;
    unsigned char  count;
    unsigned char  flags;
    unsigned short baseHi;
} __attribute__((packed)) interrupt_t;


void idtInit();

// in interrupt.s
extern void isrStub0();
extern void isrStub1();
extern void isrStub2();
extern void isrStub3();
extern void isrStub4();
extern void isrStub5();
extern void isrStub6();
extern void isrStub7();
extern void isrStub8();
extern void isrStub9();
extern void isrStub10();
extern void isrStub11();
extern void isrStub12();
extern void isrStub13();
extern void isrStub14();
extern void isrStub15();
extern void isrStub16();
extern void isrStub17();
extern void isrStub18();
extern void isrStub19();
extern void isrStub20();
extern void isrStub21();
extern void isrStub22();
extern void isrStub23();
extern void isrStub24();
extern void isrStub25();
extern void isrStub26();
extern void isrStub27();
extern void isrStub28();
extern void isrStub29();
extern void isrStub30();
extern void isrStub31();
extern void isrStub32();
extern void isrStub33();
extern void isrStub34();
extern void isrStub35();
extern void isrStub36();
extern void isrStub37();
extern void isrStub38();
extern void isrStub39();
extern void isrStub40();
extern void isrStub41();
extern void isrStub42();
extern void isrStub43();
extern void isrStub44();
extern void isrStub45();
extern void isrStub46();
extern void isrStub47();
extern void isrStub48();
extern void isrStub49();
extern void isrStub50();
extern void isrStub51();
extern void isrStub52();
extern void isrStub53();
extern void isrStub54();
extern void isrStub55();
extern void isrStub56();
extern void isrStub57();
extern void isrStub58();
extern void isrStub59();
extern void isrStub60();
extern void isrStub61();
extern void isrStub62();
extern void isrStub63();
extern void isrStub64();
extern void isrStub65();
extern void isrStub66();
extern void isrStub67();
extern void isrStub68();
extern void isrStub69();
extern void isrStub70();
extern void isrStub71();
extern void isrStub72();
extern void isrStub73();
extern void isrStub74();
extern void isrStub75();
extern void isrStub76();
extern void isrStub77();
extern void isrStub78();
extern void isrStub79();
extern void isrStub80();
extern void isrStub81();
extern void isrStub82();
extern void isrStub83();
extern void isrStub84();
extern void isrStub85();
extern void isrStub86();
extern void isrStub87();
extern void isrStub88();
extern void isrStub89();
extern void isrStub90();
extern void isrStub91();
extern void isrStub92();
extern void isrStub93();
extern void isrStub94();
extern void isrStub95();
extern void isrStub96();
extern void isrStub97();
extern void isrStub98();
extern void isrStub99();
extern void isrStub100();
extern void isrStub101();
extern void isrStub102();
extern void isrStub103();
extern void isrStub104();
extern void isrStub105();
extern void isrStub106();
extern void isrStub107();
extern void isrStub108();
extern void isrStub109();
extern void isrStub110();
extern void isrStub111();
extern void isrStub112();
extern void isrStub113();
extern void isrStub114();
extern void isrStub115();
extern void isrStub116();
extern void isrStub117();
extern void isrStub118();
extern void isrStub119();
extern void isrStub120();
extern void isrStub121();
extern void isrStub122();
extern void isrStub123();
extern void isrStub124();
extern void isrStub125();
extern void isrStub126();
extern void isrStub127();
extern void isrStub128();
extern void isrStub129();
extern void isrStub130();
extern void isrStub131();
extern void isrStub132();
extern void isrStub133();
extern void isrStub134();
extern void isrStub135();
extern void isrStub136();
extern void isrStub137();
extern void isrStub138();
extern void isrStub139();
extern void isrStub140();
extern void isrStub141();
extern void isrStub142();
extern void isrStub143();
extern void isrStub144();
extern void isrStub145();
extern void isrStub146();
extern void isrStub147();
extern void isrStub148();
extern void isrStub149();
extern void isrStub150();
extern void isrStub151();
extern void isrStub152();
extern void isrStub153();
extern void isrStub154();
extern void isrStub155();
extern void isrStub156();
extern void isrStub157();
extern void isrStub158();
extern void isrStub159();
extern void isrStub160();
extern void isrStub161();
extern void isrStub162();
extern void isrStub163();
extern void isrStub164();
extern void isrStub165();
extern void isrStub166();
extern void isrStub167();
extern void isrStub168();
extern void isrStub169();
extern void isrStub170();
extern void isrStub171();
extern void isrStub172();
extern void isrStub173();
extern void isrStub174();
extern void isrStub175();
extern void isrStub176();
extern void isrStub177();
extern void isrStub178();
extern void isrStub179();
extern void isrStub180();
extern void isrStub181();
extern void isrStub182();
extern void isrStub183();
extern void isrStub184();
extern void isrStub185();
extern void isrStub186();
extern void isrStub187();
extern void isrStub188();
extern void isrStub189();
extern void isrStub190();
extern void isrStub191();
extern void isrStub192();
extern void isrStub193();
extern void isrStub194();
extern void isrStub195();
extern void isrStub196();
extern void isrStub197();
extern void isrStub198();
extern void isrStub199();
extern void isrStub200();
extern void isrStub201();
extern void isrStub202();
extern void isrStub203();
extern void isrStub204();
extern void isrStub205();
extern void isrStub206();
extern void isrStub207();
extern void isrStub208();
extern void isrStub209();
extern void isrStub210();
extern void isrStub211();
extern void isrStub212();
extern void isrStub213();
extern void isrStub214();
extern void isrStub215();
extern void isrStub216();
extern void isrStub217();
extern void isrStub218();
extern void isrStub219();
extern void isrStub220();
extern void isrStub221();
extern void isrStub222();
extern void isrStub223();
extern void isrStub224();
extern void isrStub225();
extern void isrStub226();
extern void isrStub227();
extern void isrStub228();
extern void isrStub229();
extern void isrStub230();
extern void isrStub231();
extern void isrStub232();
extern void isrStub233();
extern void isrStub234();
extern void isrStub235();
extern void isrStub236();
extern void isrStub237();
extern void isrStub238();
extern void isrStub239();
extern void isrStub240();
extern void isrStub241();
extern void isrStub242();
extern void isrStub243();
extern void isrStub244();
extern void isrStub245();
extern void isrStub246();
extern void isrStub247();
extern void isrStub248();
extern void isrStub249();
extern void isrStub250();
extern void isrStub251();
extern void isrStub252();
extern void isrStub253();
extern void isrStub254();
extern void isrStub255();


#endif // _SMILEOS_IDT_H

// EOF
