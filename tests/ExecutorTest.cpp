#include "Executor.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
    // TestExample 1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // TestExample2
    TEST(ExecutorTest, should_return_default_pose_whne_without_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        // when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // Move Instructions
    //  TestExample1
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("M");
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // TestExample2
    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
        executor->Execute("M");
        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // TestExample3
    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        executor->Execute("M");
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // TestExample4
    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
        executor->Execute("M");
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
}