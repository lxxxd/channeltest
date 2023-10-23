#include "gtest/gtest.h"

// Test the external API
#include "ProcessingSystem.h"
#include "ChannelData.h"

TEST(ExampleTestSuite, ChannelDataTest)
{
	IneosTest::ChannelData data("channels.txt", "parameters.txt");
	EXPECT_EQ(data.get_m(), 2.0);
	EXPECT_EQ(data.get_c(), 0.5);
}


TEST(ExampleTestSuite, ProcessingSystemTest)
{
	IneosTest::ChannelData data("channels.txt","parameters.txt");
	IneosTest::ProcessingSystem system(data);
	
    EXPECT_NEAR(system.calculate_b(), 6.2698521667770093, 1e-3);	// Testing function 2
}


TEST(ExampleTestSuite, ChannelDataTest2)
{
	std::vector<double> customData = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0}; // Testing Data class when custom data is provided directly rather than from file
	IneosTest::ChannelData data(customData, 5.0, 1.5);

	EXPECT_EQ(data.get_m(), 5.0);
	EXPECT_EQ(data.get_c(), 1.5);
}

TEST(ExampleTestSuite, ProcessingSystemTest2)
{
	std::vector<double> customData = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
	IneosTest::ChannelData data(customData, 5.0, 1.5);
	IneosTest::ProcessingSystem system(data);
    EXPECT_THROW(system.calculate_b(), std::range_error);	// Testing function when faulty data causes range_error (due to division by 0 by function 3 in ProcessingSystem class)
}