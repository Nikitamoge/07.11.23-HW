#include <iostream>
#include <string>

using namespace std;

enum Entity_type { BIRD, CATTLE, HUMAN };

union Entity_characteristic {
    double flight_speed;
    bool parnopod;
    int iq;
};

struct Living_entity {
    double speed;
    Entity_type type;
    string color;
    Entity_characteristic characteristic;
};

Living_entity entities[3];

void input_entity(Living_entity& entity) {
    int type;
    cout << "Enter the entity type (0 - bird, 1 - livestock, 2 - human): ";
    cin >> type;
    if (type < 0 || type > 2){
        cout << "Uknown entity!" << endl;
        return;
    }
    entity.type = Entity_type(type);

    cout << "Enter the entity speed: ";
    cin >> entity.speed;

    cout << "Enter the entity color: ";
    cin >> entity.color;

    switch (entity.type) {
    case BIRD:
        cout << "Enter the airspeed: ";
        cin >> entity.characteristic.flight_speed;
        break;
    case CATTLE:
        cout << "Is the entity a parnopod? (1 - yes, 0 - no): ";
        cin >> entity.characteristic.parnopod;
        break;
    case HUMAN:
        cout << "Enter the IQ level: ";
        cin >> entity.characteristic.iq;
        break;
    }
}

void print_entity(const Living_entity& entity) {
    cout << "Entity type: " << entity.type << endl;
    cout << "Entity speed: " << entity.speed << endl;
    cout << "Entity color: " << entity.color << endl;

    switch (entity.type) {
    case BIRD:
        cout << "The airspeed: " << entity.characteristic.flight_speed << endl;
        break;
    case CATTLE:
        cout << "Parnopod: " << (entity.characteristic.parnopod ? "Yes" : "No") << endl;
        break;
    case HUMAN:
        cout << "IQ: " << entity.characteristic.iq << endl;
        break;
    }
}

void edit_entity(Living_entity& entity) {
    input_entity(entity);
}

void print_entities() {
    for (int i = 0; i < 3; ++i) {
        print_entity(entities[i]);
    }
}

int main() {
    for (int i = 0; i < 3; ++i) {
        input_entity(entities[i]);
    }

    print_entities();

    int index;
    cout << "Enter the entity index to edit: ";
    cin >> index;

    if (index >= 0 && index < 3) {
        edit_entity(entities[index]);
    }

    print_entities();

    return 0;
}