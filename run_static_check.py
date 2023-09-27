from subprocess import run

try:
    run("make echo", shell=True, check=True)
    run("valgrind --leak-check=full ./echo", shell=True, check=True)
    run("make clean", shell=True, check=True)
except:
    pass