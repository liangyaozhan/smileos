
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

/*
	Description:
		Interrupt Descriptor Table
	
	Arch: x86
*/


#include "idt.h"


interrupt_t idt[IDT_ENTRIES];
struct{
	unsigned short limit;
	unsigned base;
} __attribute__((packed)) idtp = {
	.limit = sizeof(interrupt_t) * IDT_ENTRIES - 1,
	.base = (unsigned int)&idt,
};


static void setup();
static void setEntry(unsigned char, unsigned int, unsigned short, unsigned char);
static void initPic();
static void load();


void idtInit(){
    
	setup();
	
	initPic();
    
    load();
    
}

static void setup(){
	setEntry(0, (unsigned int)isrStub0, 0x08, 0x8E);
    setEntry(1, (unsigned int)isrStub1, 0x08, 0x8E);
    setEntry(2, (unsigned int)isrStub2, 0x08, 0x8E);
    setEntry(3, (unsigned int)isrStub3, 0x08, 0x8E);
    setEntry(4, (unsigned int)isrStub4, 0x08, 0x8E);
    setEntry(5, (unsigned int)isrStub5, 0x08, 0x8E);
    setEntry(6, (unsigned int)isrStub6, 0x08, 0x8E);
    setEntry(7, (unsigned int)isrStub7, 0x08, 0x8E);
    setEntry(8, (unsigned int)isrStub8, 0x08, 0x8E);
    setEntry(9, (unsigned int)isrStub9, 0x08, 0x8E);
    setEntry(10, (unsigned int)isrStub10, 0x08, 0x8E);
    setEntry(11, (unsigned int)isrStub11, 0x08, 0x8E);
    setEntry(12, (unsigned int)isrStub12, 0x08, 0x8E);
    setEntry(13, (unsigned int)isrStub13, 0x08, 0x8E);
    setEntry(14, (unsigned int)isrStub14, 0x08, 0x8E);
    setEntry(15, (unsigned int)isrStub15, 0x08, 0x8E);
    setEntry(16, (unsigned int)isrStub16, 0x08, 0x8E);
    setEntry(17, (unsigned int)isrStub17, 0x08, 0x8E);
    setEntry(18, (unsigned int)isrStub18, 0x08, 0x8E);
    setEntry(19, (unsigned int)isrStub19, 0x08, 0x8E);
    setEntry(20, (unsigned int)isrStub20, 0x08, 0x8E);
    setEntry(21, (unsigned int)isrStub21, 0x08, 0x8E);
    setEntry(22, (unsigned int)isrStub22, 0x08, 0x8E);
    setEntry(23, (unsigned int)isrStub23, 0x08, 0x8E);
    setEntry(24, (unsigned int)isrStub24, 0x08, 0x8E);
    setEntry(25, (unsigned int)isrStub25, 0x08, 0x8E);
    setEntry(26, (unsigned int)isrStub26, 0x08, 0x8E);
    setEntry(27, (unsigned int)isrStub27, 0x08, 0x8E);
    setEntry(28, (unsigned int)isrStub28, 0x08, 0x8E);
    setEntry(29, (unsigned int)isrStub29, 0x08, 0x8E);
	setEntry(30, (unsigned int)isrStub30, 0x08, 0x8E);
    setEntry(31, (unsigned int)isrStub31, 0x08, 0x8E);
    
    setEntry(32, (unsigned int)isrStub32, 0x08, 0x8E);
    setEntry(33, (unsigned int)isrStub33, 0x08, 0x8E);
    setEntry(34, (unsigned int)isrStub34, 0x08, 0x8E);
    setEntry(35, (unsigned int)isrStub35, 0x08, 0x8E);
    setEntry(36, (unsigned int)isrStub36, 0x08, 0x8E);
    setEntry(37, (unsigned int)isrStub37, 0x08, 0x8E);
    setEntry(38, (unsigned int)isrStub38, 0x08, 0x8E);
    setEntry(39, (unsigned int)isrStub39, 0x08, 0x8E);
    setEntry(40, (unsigned int)isrStub40, 0x08, 0x8E);
    setEntry(41, (unsigned int)isrStub41, 0x08, 0x8E);
    setEntry(42, (unsigned int)isrStub42, 0x08, 0x8E);
    setEntry(43, (unsigned int)isrStub43, 0x08, 0x8E);
    setEntry(44, (unsigned int)isrStub44, 0x08, 0x8E);
    setEntry(45, (unsigned int)isrStub45, 0x08, 0x8E);
    setEntry(46, (unsigned int)isrStub46, 0x08, 0x8E);
    setEntry(47, (unsigned int)isrStub47, 0x08, 0x8E);
    setEntry(48, (unsigned int)isrStub48, 0x08, 0x8E);
    setEntry(49, (unsigned int)isrStub49, 0x08, 0x8E);
    setEntry(50, (unsigned int)isrStub50, 0x08, 0x8E);
    setEntry(51, (unsigned int)isrStub51, 0x08, 0x8E);
    setEntry(52, (unsigned int)isrStub52, 0x08, 0x8E);
    setEntry(53, (unsigned int)isrStub53, 0x08, 0x8E);
    setEntry(54, (unsigned int)isrStub54, 0x08, 0x8E);
    setEntry(55, (unsigned int)isrStub55, 0x08, 0x8E);
    setEntry(56, (unsigned int)isrStub56, 0x08, 0x8E);
    setEntry(57, (unsigned int)isrStub57, 0x08, 0x8E);
    setEntry(58, (unsigned int)isrStub58, 0x08, 0x8E);
    setEntry(59, (unsigned int)isrStub59, 0x08, 0x8E);
    setEntry(60, (unsigned int)isrStub60, 0x08, 0x8E);
    setEntry(61, (unsigned int)isrStub61, 0x08, 0x8E);
    setEntry(62, (unsigned int)isrStub62, 0x08, 0x8E);
    setEntry(63, (unsigned int)isrStub63, 0x08, 0x8E);
    setEntry(64, (unsigned int)isrStub64, 0x08, 0x8E);
    setEntry(65, (unsigned int)isrStub65, 0x08, 0x8E);
    setEntry(66, (unsigned int)isrStub66, 0x08, 0x8E);
    setEntry(67, (unsigned int)isrStub67, 0x08, 0x8E);
    setEntry(68, (unsigned int)isrStub68, 0x08, 0x8E);
    setEntry(69, (unsigned int)isrStub69, 0x08, 0x8E);
    setEntry(70, (unsigned int)isrStub70, 0x08, 0x8E);
    setEntry(71, (unsigned int)isrStub71, 0x08, 0x8E);
    setEntry(72, (unsigned int)isrStub72, 0x08, 0x8E);
    setEntry(73, (unsigned int)isrStub73, 0x08, 0x8E);
    setEntry(74, (unsigned int)isrStub74, 0x08, 0x8E);
    setEntry(75, (unsigned int)isrStub75, 0x08, 0x8E);
    setEntry(76, (unsigned int)isrStub76, 0x08, 0x8E);
    setEntry(77, (unsigned int)isrStub77, 0x08, 0x8E);
    setEntry(78, (unsigned int)isrStub78, 0x08, 0x8E);
    setEntry(79, (unsigned int)isrStub79, 0x08, 0x8E);
    setEntry(80, (unsigned int)isrStub80, 0x08, 0x8E);
    setEntry(81, (unsigned int)isrStub81, 0x08, 0x8E);
    setEntry(82, (unsigned int)isrStub82, 0x08, 0x8E);
    setEntry(83, (unsigned int)isrStub83, 0x08, 0x8E);
    setEntry(84, (unsigned int)isrStub84, 0x08, 0x8E);
    setEntry(85, (unsigned int)isrStub85, 0x08, 0x8E);
    setEntry(86, (unsigned int)isrStub86, 0x08, 0x8E);
    setEntry(87, (unsigned int)isrStub87, 0x08, 0x8E);
    setEntry(88, (unsigned int)isrStub88, 0x08, 0x8E);
    setEntry(89, (unsigned int)isrStub89, 0x08, 0x8E);
    setEntry(90, (unsigned int)isrStub90, 0x08, 0x8E);
    setEntry(91, (unsigned int)isrStub91, 0x08, 0x8E);
    setEntry(92, (unsigned int)isrStub92, 0x08, 0x8E);
    setEntry(93, (unsigned int)isrStub93, 0x08, 0x8E);
    setEntry(94, (unsigned int)isrStub94, 0x08, 0x8E);
    setEntry(95, (unsigned int)isrStub95, 0x08, 0x8E);
    setEntry(96, (unsigned int)isrStub96, 0x08, 0x8E);
    setEntry(97, (unsigned int)isrStub97, 0x08, 0x8E);
    setEntry(98, (unsigned int)isrStub98, 0x08, 0x8E);
    setEntry(99, (unsigned int)isrStub99, 0x08, 0x8E);
    setEntry(100, (unsigned int)isrStub100, 0x08, 0x8E);
    setEntry(101, (unsigned int)isrStub101, 0x08, 0x8E);
    setEntry(102, (unsigned int)isrStub102, 0x08, 0x8E);
    setEntry(103, (unsigned int)isrStub103, 0x08, 0x8E);
    setEntry(104, (unsigned int)isrStub104, 0x08, 0x8E);
    setEntry(105, (unsigned int)isrStub105, 0x08, 0x8E);
    setEntry(106, (unsigned int)isrStub106, 0x08, 0x8E);
    setEntry(107, (unsigned int)isrStub107, 0x08, 0x8E);
    setEntry(108, (unsigned int)isrStub108, 0x08, 0x8E);
    setEntry(109, (unsigned int)isrStub109, 0x08, 0x8E);
    setEntry(110, (unsigned int)isrStub110, 0x08, 0x8E);
    setEntry(111, (unsigned int)isrStub111, 0x08, 0x8E);
    setEntry(112, (unsigned int)isrStub112, 0x08, 0x8E);
    setEntry(113, (unsigned int)isrStub113, 0x08, 0x8E);
    setEntry(114, (unsigned int)isrStub114, 0x08, 0x8E);
    setEntry(115, (unsigned int)isrStub115, 0x08, 0x8E);
    setEntry(116, (unsigned int)isrStub116, 0x08, 0x8E);
    setEntry(117, (unsigned int)isrStub117, 0x08, 0x8E);
    setEntry(118, (unsigned int)isrStub118, 0x08, 0x8E);
    setEntry(119, (unsigned int)isrStub119, 0x08, 0x8E);
    setEntry(120, (unsigned int)isrStub120, 0x08, 0x8E);
    setEntry(121, (unsigned int)isrStub121, 0x08, 0x8E);
    setEntry(122, (unsigned int)isrStub122, 0x08, 0x8E);
    setEntry(123, (unsigned int)isrStub123, 0x08, 0x8E);
    setEntry(124, (unsigned int)isrStub124, 0x08, 0x8E);
    setEntry(125, (unsigned int)isrStub125, 0x08, 0x8E);
    setEntry(126, (unsigned int)isrStub126, 0x08, 0x8E);
    setEntry(127, (unsigned int)isrStub127, 0x08, 0x8E);
    setEntry(128, (unsigned int)isrStub128, 0x08, 0x8E);
    setEntry(129, (unsigned int)isrStub129, 0x08, 0x8E);
    setEntry(130, (unsigned int)isrStub130, 0x08, 0x8E);
    setEntry(131, (unsigned int)isrStub131, 0x08, 0x8E);
    setEntry(132, (unsigned int)isrStub132, 0x08, 0x8E);
    setEntry(133, (unsigned int)isrStub133, 0x08, 0x8E);
    setEntry(134, (unsigned int)isrStub134, 0x08, 0x8E);
    setEntry(135, (unsigned int)isrStub135, 0x08, 0x8E);
    setEntry(136, (unsigned int)isrStub136, 0x08, 0x8E);
    setEntry(137, (unsigned int)isrStub137, 0x08, 0x8E);
    setEntry(138, (unsigned int)isrStub138, 0x08, 0x8E);
    setEntry(139, (unsigned int)isrStub139, 0x08, 0x8E);
    setEntry(140, (unsigned int)isrStub140, 0x08, 0x8E);
    setEntry(141, (unsigned int)isrStub141, 0x08, 0x8E);
    setEntry(142, (unsigned int)isrStub142, 0x08, 0x8E);
    setEntry(143, (unsigned int)isrStub143, 0x08, 0x8E);
    setEntry(144, (unsigned int)isrStub144, 0x08, 0x8E);
    setEntry(145, (unsigned int)isrStub145, 0x08, 0x8E);
    setEntry(146, (unsigned int)isrStub146, 0x08, 0x8E);
    setEntry(147, (unsigned int)isrStub147, 0x08, 0x8E);
    setEntry(148, (unsigned int)isrStub148, 0x08, 0x8E);
    setEntry(149, (unsigned int)isrStub149, 0x08, 0x8E);
    setEntry(150, (unsigned int)isrStub150, 0x08, 0x8E);
    setEntry(151, (unsigned int)isrStub151, 0x08, 0x8E);
    setEntry(152, (unsigned int)isrStub152, 0x08, 0x8E);
    setEntry(153, (unsigned int)isrStub153, 0x08, 0x8E);
    setEntry(154, (unsigned int)isrStub154, 0x08, 0x8E);
    setEntry(155, (unsigned int)isrStub155, 0x08, 0x8E);
    setEntry(156, (unsigned int)isrStub156, 0x08, 0x8E);
    setEntry(157, (unsigned int)isrStub157, 0x08, 0x8E);
    setEntry(158, (unsigned int)isrStub158, 0x08, 0x8E);
    setEntry(159, (unsigned int)isrStub159, 0x08, 0x8E);
    setEntry(160, (unsigned int)isrStub160, 0x08, 0x8E);
    setEntry(161, (unsigned int)isrStub161, 0x08, 0x8E);
    setEntry(162, (unsigned int)isrStub162, 0x08, 0x8E);
    setEntry(163, (unsigned int)isrStub163, 0x08, 0x8E);
    setEntry(164, (unsigned int)isrStub164, 0x08, 0x8E);
    setEntry(165, (unsigned int)isrStub165, 0x08, 0x8E);
    setEntry(166, (unsigned int)isrStub166, 0x08, 0x8E);
    setEntry(167, (unsigned int)isrStub167, 0x08, 0x8E);
    setEntry(168, (unsigned int)isrStub168, 0x08, 0x8E);
    setEntry(169, (unsigned int)isrStub169, 0x08, 0x8E);
    setEntry(170, (unsigned int)isrStub170, 0x08, 0x8E);
    setEntry(171, (unsigned int)isrStub171, 0x08, 0x8E);
    setEntry(172, (unsigned int)isrStub172, 0x08, 0x8E);
    setEntry(173, (unsigned int)isrStub173, 0x08, 0x8E);
    setEntry(174, (unsigned int)isrStub174, 0x08, 0x8E);
    setEntry(175, (unsigned int)isrStub175, 0x08, 0x8E);
    setEntry(176, (unsigned int)isrStub176, 0x08, 0x8E);
    setEntry(177, (unsigned int)isrStub177, 0x08, 0x8E);
    setEntry(178, (unsigned int)isrStub178, 0x08, 0x8E);
    setEntry(179, (unsigned int)isrStub179, 0x08, 0x8E);
    setEntry(180, (unsigned int)isrStub180, 0x08, 0x8E);
    setEntry(181, (unsigned int)isrStub181, 0x08, 0x8E);
    setEntry(182, (unsigned int)isrStub182, 0x08, 0x8E);
    setEntry(183, (unsigned int)isrStub183, 0x08, 0x8E);
    setEntry(184, (unsigned int)isrStub184, 0x08, 0x8E);
    setEntry(185, (unsigned int)isrStub185, 0x08, 0x8E);
    setEntry(186, (unsigned int)isrStub186, 0x08, 0x8E);
    setEntry(187, (unsigned int)isrStub187, 0x08, 0x8E);
    setEntry(188, (unsigned int)isrStub188, 0x08, 0x8E);
    setEntry(189, (unsigned int)isrStub189, 0x08, 0x8E);
    setEntry(190, (unsigned int)isrStub190, 0x08, 0x8E);
    setEntry(191, (unsigned int)isrStub191, 0x08, 0x8E);
    setEntry(192, (unsigned int)isrStub192, 0x08, 0x8E);
    setEntry(193, (unsigned int)isrStub193, 0x08, 0x8E);
    setEntry(194, (unsigned int)isrStub194, 0x08, 0x8E);
    setEntry(195, (unsigned int)isrStub195, 0x08, 0x8E);
    setEntry(196, (unsigned int)isrStub196, 0x08, 0x8E);
    setEntry(197, (unsigned int)isrStub197, 0x08, 0x8E);
    setEntry(198, (unsigned int)isrStub198, 0x08, 0x8E);
    setEntry(199, (unsigned int)isrStub199, 0x08, 0x8E);
    setEntry(200, (unsigned int)isrStub200, 0x08, 0x8E);
    setEntry(201, (unsigned int)isrStub201, 0x08, 0x8E);
    setEntry(202, (unsigned int)isrStub202, 0x08, 0x8E);
    setEntry(203, (unsigned int)isrStub203, 0x08, 0x8E);
    setEntry(204, (unsigned int)isrStub204, 0x08, 0x8E);
    setEntry(205, (unsigned int)isrStub205, 0x08, 0x8E);
    setEntry(206, (unsigned int)isrStub206, 0x08, 0x8E);
    setEntry(207, (unsigned int)isrStub207, 0x08, 0x8E);
    setEntry(208, (unsigned int)isrStub208, 0x08, 0x8E);
    setEntry(209, (unsigned int)isrStub209, 0x08, 0x8E);
    setEntry(210, (unsigned int)isrStub210, 0x08, 0x8E);
    setEntry(211, (unsigned int)isrStub211, 0x08, 0x8E);
    setEntry(212, (unsigned int)isrStub212, 0x08, 0x8E);
    setEntry(213, (unsigned int)isrStub213, 0x08, 0x8E);
    setEntry(214, (unsigned int)isrStub214, 0x08, 0x8E);
    setEntry(215, (unsigned int)isrStub215, 0x08, 0x8E);
    setEntry(216, (unsigned int)isrStub216, 0x08, 0x8E);
    setEntry(217, (unsigned int)isrStub217, 0x08, 0x8E);
    setEntry(218, (unsigned int)isrStub218, 0x08, 0x8E);
    setEntry(219, (unsigned int)isrStub219, 0x08, 0x8E);
    setEntry(220, (unsigned int)isrStub220, 0x08, 0x8E);
    setEntry(221, (unsigned int)isrStub221, 0x08, 0x8E);
    setEntry(222, (unsigned int)isrStub222, 0x08, 0x8E);
    setEntry(223, (unsigned int)isrStub223, 0x08, 0x8E);
    setEntry(224, (unsigned int)isrStub224, 0x08, 0x8E);
    setEntry(225, (unsigned int)isrStub225, 0x08, 0x8E);
    setEntry(226, (unsigned int)isrStub226, 0x08, 0x8E);
    setEntry(227, (unsigned int)isrStub227, 0x08, 0x8E);
    setEntry(228, (unsigned int)isrStub228, 0x08, 0x8E);
    setEntry(229, (unsigned int)isrStub229, 0x08, 0x8E);
    setEntry(230, (unsigned int)isrStub230, 0x08, 0x8E);
    setEntry(231, (unsigned int)isrStub231, 0x08, 0x8E);
    setEntry(232, (unsigned int)isrStub232, 0x08, 0x8E);
    setEntry(233, (unsigned int)isrStub233, 0x08, 0x8E);
    setEntry(234, (unsigned int)isrStub234, 0x08, 0x8E);
    setEntry(235, (unsigned int)isrStub235, 0x08, 0x8E);
    setEntry(236, (unsigned int)isrStub236, 0x08, 0x8E);
    setEntry(237, (unsigned int)isrStub237, 0x08, 0x8E);
    setEntry(238, (unsigned int)isrStub238, 0x08, 0x8E);
    setEntry(239, (unsigned int)isrStub239, 0x08, 0x8E);
    setEntry(240, (unsigned int)isrStub240, 0x08, 0x8E);
    setEntry(241, (unsigned int)isrStub241, 0x08, 0x8E);
    setEntry(242, (unsigned int)isrStub242, 0x08, 0x8E);
    setEntry(243, (unsigned int)isrStub243, 0x08, 0x8E);
    setEntry(244, (unsigned int)isrStub244, 0x08, 0x8E);
    setEntry(245, (unsigned int)isrStub245, 0x08, 0x8E);
    setEntry(246, (unsigned int)isrStub246, 0x08, 0x8E);
    setEntry(247, (unsigned int)isrStub247, 0x08, 0x8E);
    setEntry(248, (unsigned int)isrStub248, 0x08, 0x8E);
    setEntry(249, (unsigned int)isrStub249, 0x08, 0x8E);
    setEntry(250, (unsigned int)isrStub250, 0x08, 0x8E);
    setEntry(251, (unsigned int)isrStub251, 0x08, 0x8E);
    setEntry(252, (unsigned int)isrStub252, 0x08, 0x8E);
    setEntry(253, (unsigned int)isrStub253, 0x08, 0x8E);
    setEntry(254, (unsigned int)isrStub254, 0x08, 0x8E);
    setEntry(255, (unsigned int)isrStub255, 0x08, 0x8E);
}

static void setEntry(unsigned char n, unsigned int base, unsigned short kseg, unsigned char flags){
    idt[n].baseLo = base & 0xFFFF;
    idt[n].baseHi = (base >> 16) & 0xFFFF;

    idt[n].kseg = kseg;
    idt[n].count = 0;
    
    // We must uncomment the OR below when we get to using user-mode.
    // It sets the interrupt gate's privilege level to 3.
    idt[n].flags = flags /* | 0x60 */;
}

static void initPic(){
	
	unsigned char mask1, mask2;
	
	mask1 = inb(PIC1 + 1);
	mask2 = inb(PIC2 + 1);
	
	// master pic
	outb(PIC1, PIC_ICW1);
	outb(PIC1 + 1, PIC_IRQ0);
	outb(PIC1 + 1, 0x04);
	outb(PIC1 + 1, PIC_ICW4);
	
	outb(PIC1 + 1, 0x00);
	//outb(PIC1 + 1, mask1);
	
	// slave pic
	outb(PIC2, PIC_ICW1);
	outb(PIC2 + 1, PIC_IRQ8);
	outb(PIC2 + 1, 0x02);
	outb(PIC2 + 1, PIC_ICW4);
	
	outb(PIC2 + 1, 0x00);
	//outb(PIC2 + 1, mask2);
	
}

static void load(){
	asm volatile("lidt %0" : : "m"(idtp)); // load the idt
	//asm volatile("sti"); // enable hardware interrupts
}

// EOF
