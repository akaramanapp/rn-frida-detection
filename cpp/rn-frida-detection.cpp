#include "rn-frida-detection.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifdef __ANDROID__
#include <android/log.h>
#endif

#include <iostream>
#include <future>
#include <chrono>
#include <thread>

#include <stdio.h>

#ifdef __ANDROID__
#include <jni.h>
#endif
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 512

namespace rnfridadetection {
	double multiply(double a, double b) {
		return a * b;
	}

	double bol(double a, double b) {
		return 90;
	}

    #define APPNAME "FridaDetectionTest"

#ifdef __ANDROID__
	void detect() {
        __android_log_print(ANDROID_LOG_INFO, APPNAME, "Start Frida detection");
		struct sockaddr_in sa;
		int sock, ret;
		char res[7];

        for (int i = 0; i <= 65535; i++) {
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                std::cerr << "Socket creation failed" << std::endl;
            }

            sa.sin_port = htons(i);

            if (connect(sock, reinterpret_cast<struct sockaddr*>(&sa), sizeof sa) != -1) {
                memset(res, 0, 7);

                send(sock, "\x00", 1, 0);
                send(sock, "AUTH\r\n", 6, 0);

                usleep(100); // Give it some time to answer

                ret = recv(sock, res, 6, MSG_DONTWAIT);
                if (ret != -1) {
                    if (strcmp(res, "REJECT") == 0) {
                        std::cout << "FRIDA DETECTED [1] - frida server running on port " << i << "!" << std::endl;
                    }
                }

                close(sock);
            }
        }
	}
#endif
}
