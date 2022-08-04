#include "gtest/gtest.h"
#include "../src/PreSmartBot.hpp"

class SmartBotTesting : public ::testing::Test
{
    protected:
        PreSmartBot psb;

        virtual void SetUp() override
        {
            psb = PreSmartBot(5);
        }

        void play()
        {
            
        }
}