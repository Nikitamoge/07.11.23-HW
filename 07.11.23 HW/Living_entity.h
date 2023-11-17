#pragma once
#include <string>

using namespace std;

enum Entity_type { BIRD, CATTLE, HUMAN };

union Entity_characteristic {
    double flight_speed; // для птиц
    bool parnopod; // для скота
    int iq; // для человека
};

struct Living_entity {
    double speed;
    Entity_type type;
    string color;
    Entity_characteristic characteristic;
};

void input_entity(Living_entity& entity);
void print_entity(const Living_entity& entity);
void edit_entity(Living_entity& entity);
void print_entities(Living_entity entities[], int size);
