C_COMPILER="gcc"
CPP_COMPILER="g++"

make:
	@echo "**--------- HELP ---------**"
	@echo "Run 'make cbuild' to build the C version of FDT"
	@echo "Run 'make cbuild++' to build the C++ version of FDT"
	@echo ""
	@echo "In both cases an executable called 'fdt' will be created"
	@echo "Run 'make uninstall' to delete the executable"
	@echo ""
	@echo "Alternatively you can run 'make build' to build both versions"
	@echo "This will generate both 'fdt-c' and 'fdt-cpp' which can be deleted with 'make uninstallb'"
cbuild:
	@$(C_COMPILER) fdt.c -std=c99 -o fdt
cbuild++:
	@$(CPP_COMPILER) fdt.cpp -std=c++03 -o fdt

# Just builds both
build:
	@$(C_COMPILER) fdt.c -std=c99 -o fdt-c
	@$(CPP_COMPILER) fdt.cpp -std=c++03 -o fdt-cpp
uninstall:
	@rm fdt

# Deletes files made with 'make build'
uninstallb:
	@rm fdt-c
	@rm fdt-cpp
