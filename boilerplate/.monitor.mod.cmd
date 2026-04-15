savedcmd_/home/muk/OS-Project/boilerplate/monitor.mod := printf '%s\n'   monitor.o | awk '!x[$$0]++ { print("/home/muk/OS-Project/boilerplate/"$$0) }' > /home/muk/OS-Project/boilerplate/monitor.mod
