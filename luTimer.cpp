#include <libnotify/notify.h>
#include <string>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    /* usage: luTimer 11
     *    11 minutes timer */
    if(argc != 2) {
        cout << "usage: luTimer 12" << endl;
        return 0;
    }

    string provTime(argv[1]);
    int sleep_time(stoi(provTime));
    usleep((useconds_t) (sleep_time * 1e6 * 60));

    if (!notify_init("timeNotfy")) return 0;
    NotifyNotification* notProv = notify_notification_new("timeout!!!!", "<i>eai amigows *~*</i>", "/home/yes0/Pictures/luffy-icon.png");
    notify_notification_set_urgency(notProv, NOTIFY_URGENCY_CRITICAL);
    notify_notification_show(notProv, NULL);

    string cmd("mpg123 -q -n 80 /home/yes0/Notification-Sounds/piece-of-cake.mp3");
    system(cmd.c_str());


    g_object_unref(G_OBJECT(notProv));
    notify_uninit();
    return 0;
}

