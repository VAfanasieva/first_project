#ifndef DECISION_H
#define DECISION_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "roots.h"
}

TEST(decisionTest, num_roots_2) {
    ASSERT_EQ(decision(-1, 7, 8).x1, -1);
    ASSERT_EQ(decision(-1, 7, 8).x2, 8);
}

TEST(decisionTest, doudle_roots){
    ASSERT_EQ(decision(1.2, 3, -5.6).x1, 1.2458298553119895);
    ASSERT_EQ(decision(1.2, 3, -5.6).x2, -3.7458298553119893);


}
TEST(decisionTest, big_roots){
    ASSERT_EQ(decision(1234567563, 345345, -43534433).x1, 0.1876443730020721);
    ASSERT_EQ(decision(1234567563, 345345, -43534433).x2, -0.18792410252870959);

}

TEST(decisionTest, num_roots_1){
    ASSERT_EQ(decision(1, -4, 4).x1, 2);

}

TEST(decisionTest, num_roots_0) {
    ASSERT_EQ(decision(1, -5, 9).count_roots, 0);
    ASSERT_EQ(decision(0, 0, 8).count_roots, 0);
    ASSERT_EQ(decision(0, 0, 0).count_roots, 0);

}

TEST(decisionTest, not_square) {
    ASSERT_EQ(decision(0, 2, 8).x1, -4);
}

TEST(decisionTest, inputFile) {
    val = 5;
    char *filename = (char *)malloc(sizeof(char) * 1024);
    sprintf(filename, "%s/inputRoots.txt", INPUTDIR);

    int fd = open(filename, O_RDONLY);
    free(filename);
    if (fd < 0) {
        ASSERT_EQ(errno, 0);
    }

    char *buf = (char *)malloc(sizeof(char) * 512);
    int readcount = read(fd, buf, 512);
    ASSERT_TRUE(readcount > 0);
    close(fd);

    int a = 0;
    int b = 0;
    int c = 0;
    int x1 = 0;
    int x2 = 0;
    int ret = sscanf(buf, "%d %d %d %d %d", &a, &b, &c, &x1, &x2);
    free(buf);
    ASSERT_EQ(ret, 5);

    ASSERT_EQ(decision(a, b, c).x1, x1);
    ASSERT_EQ(decision(a, b, c).x2, x2);
}

#endif
