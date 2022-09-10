#ifndef CHILDREN_HPP_
#define CHILDREN_HPP_
#pragma once

const int name_size = 256;
const int gen_size = 10;
const int subj_size = 256;


struct subject {
    char name[subj_size];
    int* estims;
    int es_size;
};

struct children {
    char name[name_size];
    char gen[gen_size];
    int height;
    int age;
    subject* subjs;
    int subj_size;
};

#endif
