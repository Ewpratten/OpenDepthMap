#include <iostream>
#include "../dist/Leap.h"

using namespace Leap;

//---- Start Public Functions ----//
extern "C" void beginEventLoop();
extern "C" bool isControllerCreated();
extern "C" void endEventLoop();
extern "C" void updateFrame();
extern "C" bool imageExists();
extern "C" int getImageHeight();
extern "C" int getImageWidth();
extern "C" int getImageBPP();
extern "C" const unsigned char *getImageLeft();
extern "C" const unsigned char *getImageRight();
//---- End Public Functions ----//

//---- Start Globals ----//
Controller *controller = nullptr;
Frame *frame = nullptr;
//---- End Globals ----//

//---- Start Public Function Impls ----//

void beginEventLoop()
{
    if (controller == nullptr)
    {
        // Create a controller
        controller = new Controller();

        // Set device policy
        controller->setPolicy(Controller::POLICY_IMAGES);
        controller->setPolicy(Controller::POLICY_OPTIMIZE_HMD);

    }
}

void endEventLoop()
{
    if (controller != nullptr)
    {
        delete controller;
    }
}

void updateFrame()
{
    // free(frame);
    // Frame f = controller->frame();
    // frame = (Frame*) malloc(sizeof(f));
    // memccpy(frame, f);
}

bool isControllerCreated() { return controller != nullptr; }
bool imageExists() { return controller->frame().images().count() == 2; }
int getImageHeight() { return controller->frame().images()[0].height(); }
int getImageWidth() { return controller->frame().images()[0].width(); }
int getImageBPP() { return controller->frame().images()[0].bytesPerPixel(); }
const unsigned char *getImageLeft() { return controller->frame().images()[0].data(); }
const unsigned char *getImageRight() { return controller->frame().images()[1].data(); }

//---- End Public Function Impls ----//
