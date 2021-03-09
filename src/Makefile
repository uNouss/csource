all:
	@(cd libbcb && make install)
	@(cd libvext && make install)
	@(cd disterre && make install)
	@(cd util && make install)
	@(cd pvc && make)

clean :
	@(cd libvext && make clean)
	@(cd libbcb && make clean)
	@(cd disterre && make clean)
	@(cd util && make clean)
	@(cd pvc && make clean)

mrproper: clean
	@(cd libvext && make mrproper)
	@(cd libbcb && make mrproper)
	@(cd disterre && make mrproper)
	@(cd util && make mrproper)
	# @(cd pvc && make mrproper)
