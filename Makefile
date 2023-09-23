Greenspace.smc: Greenspace.asm Greenspace.link
	wla-65816 -o Greenspace.obj Greenspace.asm
	wlalink Greenspace.link Greenspace.smc