greenspace.smc: greenspace.asm greenspace.link
	wla-65816 -o greenspace.o greenspace.asm
	wlalink greenspace.link greenspace.smc