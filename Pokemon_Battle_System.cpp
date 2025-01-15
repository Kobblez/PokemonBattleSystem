#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdlib>

using namespace std;
/*
0.  None
1.  Bug
2.  Dark
3.  Dragon
4.  Electric
5.  Fairy
6.  Fighting
7.  Fire
8.  Flying
9.  Ghost
10. Grass
11. Ground
12. Ice
13. Normal
14. Poison
15. Psychic
16. Rock
17. Steel
18. Water
*/

//To figure the type multiplier for moves
int type_effectiveness(int atk, int def1, int def2) {
    int eff = 0, i = 0, j = def1;

    //Type Immunities
    //Dark is Psychic Immune
    if (atk == 15 && (def1 == 2 || def2 == 2))
        return 10;
    //Fairy is Dragon Immune
    if (atk == 3 && (def1 == 5 || def2 == 5))
        return 10;
    //Flying is Ground Immune
    if (atk == 11 && (def1 == 8 || def2 == 8))
        return 10;
    //Ghost is Normal and Fighting Immune
    if ((atk == 6 || atk == 13) && (def1 == 9 || def2 == 9))
        return 10;
    //Ground is Electric Immune
    if (atk == 4 && (def1 == 11 || def2 == 11))
        return 10;
    //Normal is Ghost Immune
    if (atk == 9 && (def1 == 13 || def2 == 13))
        return 10;
    //Steel is Poison Immune
    if (atk == 14 && (def1 == 17 || def2 == 17))
        return 10;

    //Type chart without the immunities
    //Immunites are done above
    while (i < 2) {
        switch (j) {
        case 0: eff += 0;
            break;
        case 1: //Bug
            switch (atk) {
            case 6: eff -= 1;//Fighting
                break;
            case 7: eff += 1;//Fire
                break;
            case 8: eff += 1;//Flying
                break;
            case 10: eff -= 1;//Grass
                break;
            case 11: eff -= 1;//Ground
                break;
            case 16: eff += 1;//Rock
                break;
            default: eff += 0;
            }
            break;
        case 2: //Dark
            switch (atk) {
            case 1: eff += 1;//Bug
                break;
            case 2: eff -= 1;//Dark
                break;
            case 5: eff += 1;//Fairy
                break;
            case 6: eff += 1;//Fighting
                break;
            case 9: eff -= 1;//Ghost
                break;
            default: eff += 0;
            }
            break;
        case 3: //Dragon
            switch (atk) {
            case 3: eff += 1;//Dragon
                break;
            case 4: eff -= 1;//Electric
                break;
            case 5: eff += 1;//Fairy
                break;
            case 7: eff -= 1;//Fire
                break;
            case 10: eff -= 1;//Grass
                break;
            case 12: eff += 1;//Ice
                break;
            case 18: eff -= 1;//Water
                break;
            default: eff += 0;
            }
            break;
        case 4: //Electric
            switch (atk) {
            case 4: eff -= 1;//Electric
                break;
            case 8: eff -= 1;//Flying
                break;
            case 11: eff += 1;//Ground
                break;
            case 17: eff -= 1;//Steel
                break;
            default: eff += 0;
            }
            break;
        case 5: //Fairy
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 2: eff -= 1;//Dark
                break;
            case 6: eff -= 1;//Fighting
                break;
            case 14: eff += 1;//Poison
                break;
            case 17: eff += 1;//Steel
                break;
            default: eff += 0;
            }
            break;
        case 6: //Fighting
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 2: eff -= 1;//Dark
                break;
            case 5: eff += 1;//Fairy
                break;
            case 8: eff += 1;//Flying
                break;
            case 15: eff += 1;//Psychic
                break;
            case 16: eff -= 1;//Rock
                break;
            default: eff += 0;
            }
            break;
        case 7: //Fire
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 5: eff -= 1;//Fairy
                break;
            case 7: eff -= 1;//Fire
                break;
            case 10: eff -= 1;//Grass
                break;
            case 11: eff += 1;//Ground
                break;
            case 12: eff -= 1;//Ice
                break;
            case 16: eff += 1;//Rock
                break;
            case 17: eff -= 1;//Steel
                break;
            case 18: eff += 1;//Water
                break;
            default: eff += 0;
            }
            break;
        case 8: //Flying
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 4: eff += 1;//Electric
                break;
            case 6: eff -= 1;//Fighting
                break;
            case 10: eff -= 1;//Grass
                break;
            case 12: eff += 1;//Fire
                break;
            case 16: eff += 1;//Rock
                break;
            default: eff += 0;
            }
            break;
        case 9: //Ghost
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 2: eff += 1;//Dark
                break;
            case 9: eff += 1;//Ghost
                break;
            case 14: eff -= 1;//Poison
                break;
            default: eff += 0;
            }
            break;
        case 10: //Grass
            switch (atk) {
            case 1: eff += 1;//Bug
                break;
            case 4: eff -= 1;//Electric
                break;
            case 7: eff += 1;//Fire
                break;
            case 8: eff += 1;//Flying
                break;
            case 10: eff -= 1;//Grass
                break;
            case 11: eff -= 1;//Ground
                break;
            case 12: eff += 1;//Ice
                break;
            case 14: eff += 1;//Poison
                break;
            case 18: eff -= 1;//Water
                break;
            default: eff += 0;
            }
            break;
        case 11: // Ground
            switch (atk) {
            case 10: eff += 1;//Grass
                break;
            case 12: eff += 1;//Ice
                break;
            case 14: eff -= 1;//Poison
                break;
            case 16: eff -= 1;//Rock
                break;
            case 18: eff += 1;//Water
                break;
            default: eff += 0;
            }
            break;
        case 12: //Ice
            switch (atk) {
            case 6: eff += 1;//Fighting
                break;
            case 7: eff += 1;//Fire
                break;
            case 12: eff -= 1;//Ice
                break;
            case 16: eff += 1;//Rock
                break;
            case 17: eff += 1;//Steel
                break;
            default: eff += 0;
            }
            break;
        case 13: //Normal
            switch (atk) {
            case 6: eff += 1;//Fighting
                break;
            default: eff += 0;
            }
            break;
        case 14: //Poison
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 5: eff -= 1;//Fairy
                break;
            case 6: eff -= 1;//Fighting
                break;
            case 10: eff -= 1;//Grass
                break;
            case 11: eff += 1;//Grounnd
                break;
            case 14: eff -= 1;//Poison
                break;
            case 15: eff += 1;//Psychic
                break;
            default: eff += 0;
            }
            break;
        case 15: //Psychic
            switch (atk) {
            case 1: eff += 1;//Bug
                break;
            case 2: eff += 1;//Dark
                break;
            case 6: eff -= 1;//Fighting
                break;
            case 9: eff += 1;//Ghost
                break;
            case 15: eff -= 1;//Psychic
                break;
            default: eff += 0;
            }
            break;
        case 16: //Rock
            switch (atk) {
            case 6: eff += 1;//Fighting
                break;
            case 7: eff -= 1;//Fire
                break;
            case 8: eff -= 1;//Flying
                break;
            case 10: eff += 1;//Grass
                break;
            case 11: eff += 1;//Grounnd
                break;
            case 13: eff -= 1;//Normal
                break;
            case 14: eff -= 1;//Poison
                break;
            case 17: eff += 1;//Steel
                break;
            case 18: eff += 1;//Water
                break;
            default: eff += 0;
            }
            break;
        case 17: //Steel
            switch (atk) {
            case 1: eff -= 1;//Bug
                break;
            case 3: eff -= 1;//Dragon
                break;
            case 5: eff -= 1;//Fairy
                break;
            case 6: eff += 1;//Fighting
                break;
            case 7: eff += 1;//Fire
                break;
            case 8: eff -= 1;//Flying
                break;
            case 10: eff -= 1;//Grass
                break;
            case 11: eff += 1;//Ground
                break;
            case 12: eff -= 1;//Ice
                break;
            case 13: eff -= 1;//Normal
                break;
            case 15: eff -= 1; //Psychic
                break;
            case 16: eff -= 1;//Rock
                break;
            case 17: eff -= 1;//Steel
                break;
            default: eff += 0;
            }
            break;
        case 18: //Water
            switch (atk) {
            case 4: eff += 1;//Electric
                break;
            case 7: eff -= 1;//Fire
                break;
            case 10: eff += 1;//Grass
                break;
            case 12: eff -= 1;//Ice
                break;
            case 17: eff -= 1;//Steel
                break;
            case 18: eff -= 1;//Water
                break;
            default: eff += 0;
            }
            break;
        default: eff += 0;

        }
        i++;
        j = def2;
    }
    return eff;
}

//To find the accuracy of the move in the specific instance
int accuracy(int move_acc, double stage_multi) {
    int accuracy;
    double temp_acc;

    //The actual accuracy of the occurence
    temp_acc = move_acc * stage_multi;

    //Round
    accuracy = round(temp_acc);

    return accuracy;
}

//To see if the move used connects
bool move_connection(int acc) {
    int chance = 100 - acc, random;
    //To try to get as close to true random as possible
    srand(time(0));
    //To make the range 0-100
    random = (rand() % 100);
    //Hit
    if (random >= chance)
        return true;
    //Miss
    else
        return false;
}

//Displays a menu for the types
void type_menu() {
    cout << "Pokemon Types" << endl;
    cout << "0.  None" << endl
        << "1.  Bug" << endl
        << "2.  Dark" << endl
        << "3.  Dragon" << endl
        << "4.  Electric" << endl
        << "5.  Fairy" << endl
        << "6.  Fighting" << endl
        << "7.  Fire" << endl
        << "8.  Flying" << endl
        << "9.  Ghost" << endl
        << "10. Grass" << endl
        << "11. Ground" << endl
        << "12. Ice" << endl
        << "13. Normal" << endl
        << "14. Poison" << endl
        << "15. Psychic" << endl
        << "16. Rock" << endl
        << "17. Steel" << endl
        << "18. Water" << endl << endl;
}

//****Need to actually finish this****
bool target_burned() {
    return false;
}

//****Need to implement crit stage, but otherwise done****
bool move_crit() {
    srand(time(0));
    int crit_chance = (rand() % 24) + 1;
    int crit_stage = 0; //****Change when crit stage is implemented****
    //4.17% or 1/24 crit chance
    if (crit_stage == 0 && crit_chance == 1)
        return true;
    //12.5% or 1/8 crit chance
    if (crit_stage == 1 && crit_chance <= 3)
        return true;
    //50% or 1/2 crit chance
    if (crit_stage == 2 && crit_chance <= 12)
        return true;
    //100% crit chance
    if (crit_stage >= 3)
        return true;
    //No crit
    return false;
}

//****Need to actually finish this****
int weather(string curr_weath) {
    int weather_type = 0;
    if (curr_weath == "sun")
        weather_type = 1;
    if (curr_weath == "rain")
        weather_type = 2;
    if (curr_weath == "sandstorm")
        weather_type = 3;
    if (curr_weath == "hail")
        weather_type = 4;
    if (curr_weath == "clear")
        weather_type = 0;
    return weather_type;
}

//Stage modifiers for Attack, Defense, Special Attack, Special Defense and Speed
double stage_mod(int stage) {
    double stage_multi;
    switch (stage) {
    case -6: stage_multi = 2 / 8 ;
        break;
    case -5: stage_multi = 2 / 7;
        break;
    case -4: stage_multi = 2 / 6;
        break;
    case -3: stage_multi = 2 / 5;
        break;
    case -2: stage_multi = 2 / 4;
        break;
    case -1: stage_multi = 2 / 3;
        break;
    case 0: stage_multi = 2 / 2;
        break;
    case 1: stage_multi = 3 / 2;
        break;
    case 2: stage_multi = 4 / 2;
        break;
    case 3: stage_multi = 5 / 2;
        break;
    case 4: stage_multi = 6 / 2;
        break;
    case 5: stage_multi = 7 / 2;
        break;
    case 6: stage_multi = 8 / 2;
        break;
    }
    //To 2 decimal places
    stage_multi = round(stage_multi * 100) / 100.00;
    return stage_multi;
}

/*Stage modifiers for Accuracy and Evasion combined.
Is different form other stage modifiers due to Accuracy
and Evasion being directly linked.*/
double stage_mod_acc_eva(int evas_stage, int acc_stage) {
    int stage = 0;
    double stage_multi, numer = 3, denom = 3;
    stage = acc_stage - evas_stage;
    //Maxes out at 6
    if (stage > 6)
        stage = 6;
    //Mins out at -6
    else if (stage < -6)
        stage = -6;
    if (stage < 0)
        numer += stage;
    else if (stage > 0)
        denom -= stage;

    //Get the actual multiplier
    stage_multi = numer / denom;
    //Round to nearest hundreth
    stage_multi = round(stage_multi * 100) / 100.00;

    return stage_multi;
}



//Things to add:
int main()
{
    string weath = "clear";
    int attack, att1, att2,
        def1, def2,
        categ,
        n, //Help in type effectiveness
        choice,
        acc, acc_final, eva_stage = 0, acc_stage = 0, accuracy_multi,
        att_stage = 0, temp_att_stage,
        def_stage = 0, temp_def_stage,
        spatt_stage = 0, temp_spatt_stage,
        spdef_stage = 0, temp_spdef_stage,
        spd_stage = 0,
        power,
        init_roll,
        damage,
        hp = 300,
        turn = 1,
        //weather_turn,
        sky = 0;
    double type_eff,
        roll,
        att_multi,
        def_multi,
        spatt_multi,
        spdef_multi,
        spd_multi,
        burn_multi = 1.0,
        crit_multi = 1.0,
        stab_multi = 1.0,
        weath_multi = 1.0,
        //Temporary for damage formula
        stat_att = 100.00,
        stat_spatt = 100.00,
        A,
        stat_def = 100.00,
        stat_spdef = 100.00,
        D,
        level = 100.00,
        pre_damage;
        //End of temp
    bool connect,
        crit,
        burn;
    //For display reference purpose
    const char* typing[] = { "None", "Bug", "Dark", "Dragon", "Electric", "Fairy", "Fighting",
                            "Fire", "Flying", "Ghost", "Grass", "Ground", "Ice", "Normal",
                            "Poison", "Psychic", "Rock", "Steel", "Water" };
    //Types menu
    type_menu();
    
    while (true) {
        cout << "Target's current HP = " << hp << endl;
        //Att1 type input
        while (true) {
            cout << "Enter attacker's first type number: ";
            cin >> att1;
            //Make sure input is within range
            if (att1 < 0 || att1 > 18) {
                cout << "**Please select an appropriate type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            //Check for input of 'None' type
            else if (att1 == 0) {
                cout << "**The attacker's first type must have a type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Att2 type input
        while (true) {
            cout << "Enter attacker's second type number (if no second type, type '0' for none): ";
            cin >> att2;
            //Make sure input is within range
            if (att2 < 0 || att2 > 18) {
                cout << "**Please select an appropriate type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            //Check for duplicate type
            else if (att1 == att2) {
                cout << "**The attacker's second type cannot be the same as the attacker's first type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Attack type input
        while (true) {
            cout << "Enter in the attack type number: ";
            cin >> attack;
            //Make sure input is within range
            if (attack < 0 || attack > 18) {
                cout << "**Please select an appropriate type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            //Check for an input of 'None' type
            else if (attack == 0) {
                cout << "**The attack must have a type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Attack Power
        while (true){
            cout << "Enter the base power of the move: ";
            cin >> power;
            if (power < 0 || power > 250) {
                cout << "**Please enter a power between 1 and 250**" <<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Attack Accuracy
        while (true) {
            cout << "Enter the base accuracy of the move: ";
            cin >> acc;
            if (acc < 0 || acc > 101) {
                cout << "**Accuracy must be between 0 and 101**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Category of attack
        while (true) {
            cout << "Move category:\n1. Physical\n2. Special\n3. Status\nPlease select one of the above:  ";
            cin >> categ;
            if (categ < 1  || categ > 3) {
                cout << "**Please select an appropriate choice.**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Def1 type input
        while (true) {
            cout << "Enter first defense type number: ";
            cin >> def1;
            //Make sure input is within range
            if (def1 < 0 || def1 > 18) {
                cout << "**Please select an appropriate type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            //Check for input of 'None' type
            else if (def1 == 0) {
                cout << "**The first defense must have a type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Def2 type input
        while (true) {
            cout << "Enter second defense type number (if no second type, type '0' for none): ";
            cin >> def2;
            //Make sure input is within range
            if (def2 < 0 || def2 > 18) {
                cout << "**Please select an appropriate type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            //Check for duplicate type
            else if (def1 == def2) {
                cout << "**The second defense type cannot be the same as the first defense type**" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
        //Display inputs
        //For 1 defense type
        if (def2 == 0) {
            cout << "\nAttack Type: " << typing[attack] << endl
                << "Defense Type: " << typing[def1] << endl;
        }
        //For 2 defense types
        else {
            cout << "\nAttack Type: " << typing[attack] << endl
                << "Defense Type: " << typing[def1] << '/' << typing[def2] << endl;
        }
        cin.ignore(1000, '\n');

        //The over-arching stat
        spd_multi = stage_mod(spd_stage);

        
        //To find the type effectiveness
        n = type_effectiveness(attack, def1, def2);
        if (n == 10)
            type_eff = 0;
        else
            type_eff = pow(2, n);

        cout << "Type effectiveness: x" << type_eff << endl;

        //If immune, the rest of the calculations don't matter
        if (type_eff != 0) {
            accuracy_multi = stage_mod_acc_eva(eva_stage, acc_stage);
            acc_final = accuracy(acc, accuracy_multi);
            connect = move_connection(acc_final);

            //If a miss, the rest of the calculations don't matter
            if (connect) {
                //STAB (same type attack bonus)
                if (attack == att1 || attack == att2)
                    stab_multi = 1.5;

                //To determine the random roll of the move
                srand(time(0));
                init_roll = ((rand() % (100 - 85)) + 85) / 1; //Gives a random whole number between 85-100
                roll = init_roll / 100.00; //Makes it a decimal

                burn = target_burned();
                //Implementing burn
                if (burn)
                    burn_multi = 0.5;
                

                sky = weather(weath);
                //For when I get weather working
                //Sun is out
                if (sky == 1){
                    //Boost fire by 50%
                    if (attack == 7)
                        weath_multi = 1.5;
                    //Half water damage
                    if (attack == 18)
                        weath_multi = 0.5;
                }
                //It is raining
                if (sky == 2){
                    //Half fire damage
                    if (attack == 7)
                        weath_multi = 0.5;
                    //Boost water by 50%
                    if (attack == 18)
                        weath_multi = 1.5;
                }
                if (sky == 0)
                    weath_multi = 0; //Maybe should equl 1, gotten get used to th code again

                crit = move_crit();
                //Ignorances when the move crits
                if (crit) {
                    crit_multi = 1.5;
                    //Ignores positive defense stages
                    if (def_stage > 0)
                        temp_def_stage = 0;
                    //Ignores negative attack stages
                    if (att_stage < 0)
                        temp_att_stage = 0;
                    //Ignores positive special defense stages
                    if (spdef_stage > 0)
                        temp_spdef_stage = 0;
                    //Ignores negative special attack stages
                    if (spatt_stage < 0)
                        temp_spatt_stage = 0;
                }

                //In case of no crit
                temp_att_stage = att_stage;
                temp_def_stage = def_stage;
                temp_spatt_stage = spatt_stage;
                temp_spdef_stage = spdef_stage;

                //To be applied to main stats in damage calcutlation
                att_multi = stage_mod(temp_att_stage);
                def_multi = stage_mod(temp_def_stage);
                spatt_multi = stage_mod(temp_spatt_stage);
                spdef_multi = stage_mod(temp_spdef_stage);

                //For physical attacks
                if (categ == 1) {
                    A = stat_att * att_multi;
                    D = stat_def * def_multi;
                }
                //For special attacks
                if (categ == 2) {
                    A = stat_spatt * spatt_multi;
                    D = stat_spdef * spdef_multi;
                }

                //Damage Formula
                pre_damage = ((((2 * level) / 5) + 2) * power * (A / D)) / 50 + 2;
                damage = round(pre_damage * crit_multi * burn_multi * stab_multi * type_eff * roll);

                //Hit
                cout << "Move hit!!" << endl;
                if (crit)
                    cout << "It's a critical hit!!" << endl;
                if (type_eff > 0 && type_eff < 1)
                    //For x0.25 and 0.5
                    cout << "It's not very effective." << endl;
                else if (type_eff > 1)
                    //For x2 and x4
                    cout << "It's super effective." << endl;
                //No need to display damage that exceeds the HP
                if (damage > hp) 
                    cout << "The move hit for " << hp << " damage." << endl;
                //If damage does not exceed HP
                else
                    cout << "The move hit for " << damage << " damage." << endl;
                
                //HP calculation
                hp -= damage;
                if (hp < 0)
                    hp = 0;
                if (hp == 0) {
                    cout << "\nTarget has fainted.\nThe battle is over.";
                    return 0;
                }
            }
            //Miss
            else
                cout << "Attack missed." << endl;
        }
        //Immune
        else
            cout << "Target is immune." << endl;


        //Reset of multipliers
        crit_multi = 1;
        stab_multi = 1;
        burn_multi = 1;

        //Continuation Menu
        cout << endl << "1. Next turn?\n2. Exit" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 2)
            return 0;
        cin.clear();
        cin.ignore(1000, '\n');
        turn++;
    }
    
}