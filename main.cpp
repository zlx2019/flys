#include <iostream>
#include <sys/socket.h>
#include <sys/event.h>
#include <sys/types.h>
#include <unistd.h>
#include <fmt/format.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>

// 传统 错误处理,根据 errno
void error_handing(int res, const char *message){
    if (res == -1){
        // 将错误信息转换为中文.
        setlocale(LC_ALL, "zh_CN.UTF-8");
        fmt::println("{} errno: [{}], cause: {}", message, errno, strerror(errno));
        exit(1);
    }
}


/**
 * 使用C++ 编写一个 HTTP 服务
 */
int main(){
    // 将指定的地址转换为一个或多个 addrinfo 结构体.
    struct addrinfo *addr;
    int err = getaddrinfo("127.0.0.1", "8088", NULL, &addr);
    if (err != 0){
        // gai 错误处理.
        fmt::println("parse addr fail: {}", gai_strerror(err));
        return 1;
    }
    // fmt::println("{}", addr->ai_family);    // 协议版本 2 = AF_INET(IPv4)  10 = AF_INET6(IPv6)
    // fmt::println("{}", addr->ai_socktype);  // 套接字类型 SOCK_STREAM(TCP)  SOCK_DGRAM(UDP)
    // fmt::println("{}", addr->ai_protocol);  // 6 = IPPROTO_TCP 17 = IPPROTO_UDP

    // 创建 socket 服务
    // socket(AF_INET, SOCK_STREAM, 0);
    int sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    error_handing(sockfd, "create socket server fail");
    return 0;
}