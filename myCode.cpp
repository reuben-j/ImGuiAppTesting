//
//  myCode.cpp
//  example_osx_opengl2
//
//  Created by Reuben Jarvela on 16/08/2024.
//  Copyright © 2024 ImGui. All rights reserved.
//

#include "myCode.hpp"
#include "imgui.h"
#include <stdio.h>
#include <iostream>
#include <cmath>


using namespace std;



namespace myCode
{
void RenderUI() {
    
    static int counter = 0;
    
    ImGui::Begin("Test Page");
    
    if(ImGui::Button("+1")) {
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text("Counter: %d", counter);
    ImGui::Text("Reuben is KOOL");
    
    ImGui::End();
    
}

void RenderNewPage(){
    ImGui::Begin("Second Page");
    ImGui::Text("Hiya");
    ImGui::End();
}

double returnCalc(char operatorSign, double num1, double num2) {
    switch (operatorSign) {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1 * num2;
            break;
        case '/':
            return num1 / num2;
            break;
        case '^':
            return pow(num1, num2);
            break;
        case '|':
            return sqrt(num1);
            break;
        case '%':
            return int(num1) % int(num2);
            break;
            
        default:
            break;
    }
    return 0;
}

void CalculatorWindow(){

    static char operatorCalc;
    static int op = 0;
    static double inputInt1, inputInt2;
    
    ImGui::Begin("Calculator");
    
    ImGui::InputDouble("###", &inputInt1);
    
    if(ImGui::RadioButton("Add", &op, 0)) {
        operatorCalc = '+';
    }; ImGui::SameLine();
    
    if(ImGui::RadioButton("Sub", &op, 1)) {
        operatorCalc = '-';
    };
    if(ImGui::RadioButton("Tim", &op, 2)) {
        operatorCalc = '*';
    }; ImGui::SameLine();
    if(ImGui::RadioButton("Div", &op, 3)) {
        operatorCalc = '/';
    };
    if(ImGui::RadioButton("Pow", &op, 4)) {
        operatorCalc = '^';
    }; ImGui::SameLine();
    if(ImGui::RadioButton("SqRt", &op, 5)) {
        operatorCalc = '|';
    };
    if(ImGui::RadioButton("Mod", &op, 6)) {
        operatorCalc = '%';
    };
    
    ImGui::InputDouble("##", &inputInt2);
    
    ImGui::Text("Output: %0.3f", returnCalc(operatorCalc, inputInt1, inputInt2));
    
    ImGui::End();
}

void nameRender(){
    static char name[128];
    ImGui::Text("What is your name?");
    ImGui::InputText("##", name, IM_ARRAYSIZE(name));
    ImGui::Text("Hi %s", name);
}

}


