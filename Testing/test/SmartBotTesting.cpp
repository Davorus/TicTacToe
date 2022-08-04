#include <iostream>
#include <vector>

#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../src/PreSmartBot.hpp"
#include "../src/Random_Bot.hpp"

class SmartBotTesting : public ::testing::Test
{
    protected:
        PreSmartBot smart;
        Random_Bot random;

        virtual void SetUp() override
        {
            smart = PreSmartBot(5);
            random = Random_Bot(3);

            std::vector<std::vector<int>> tempVector(3, std::vector<int>(3)); 

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    tempVector.at(i).at(j) = 0;
                }
            }
            this->m_testfield.assign(tempVector.begin(), tempVector.end());
        }

        void play()
        {
            std::cout << "Test starts..." << std::endl;
        }

    public:
        std::vector<std::vector<int>> m_testfield;
};