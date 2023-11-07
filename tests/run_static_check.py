from subprocess import run

try:
    run("make echo_mock", shell=True, check=True)
    run("valgrind --leak-check=full --track-origins=yes ./echo_mock", shell=True, check=True)
    run("make clean", shell=True, check=True)
except:
    pass