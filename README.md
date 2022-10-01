Manual:
1. After cloning the project 
type:
1.1 git submodule init
1.2 git submodule update
to download googletest repo to the project
2. For use Multhitreading option type:
cmake . -DENABLE_MULTHITHREADING=1
make all
./MainProgramm
