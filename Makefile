all : desc target

desc :
	@echo "MAKEFILE说明："
	@echo "此MAKEFILE为编译XXX程序所用"
	@echo "如果需要XXX"
	@echo ""

target : obj.o
