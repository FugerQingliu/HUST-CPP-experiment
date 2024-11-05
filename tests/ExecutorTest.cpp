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
}