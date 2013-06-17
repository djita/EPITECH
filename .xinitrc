## BOCAL STAFF 2010-2011
## FEDORA DUMP

WM="startfluxbox"
TERM="xterm"
END="dclock"
XCM="xcompmgr -c " # -r20 -f -F -D5 -C -o1"

xhost -
xset b off

if [ -f ${HOME}/.Xdefaults ]
then
    xrdb ${HOME}/.Xdefaults
fi

if [ ! -f ${HOME}/.fluxbox/menu ]
then
    if [ ! -d ${HOME}/.fluxbox ]
    then
	mkdir ${HOME}/.fluxbox
	chmod 700 ${HOME}/.fluxbox
    fi
    fluxbox-generate_menu -b google-chrome -m IIT -t xterm -w google.com
    sed -e '152a [exec] (Shutdown) {poweroff }\n[exec] (Reboot) {reboot }' -i ${HOME}/.fluxbox/menu
fi

exec ${WM} &
exec ${XCM} &
exec ${TERM} &
exec ${END}
# EOF
