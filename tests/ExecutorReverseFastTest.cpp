#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
    TEST(ExecutorReverseFastTest, should_return_x_minus_2_given_status_is_fast_and_reverse_command_is_M_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        executor->Execute("FBM");

        const Pose target{-2, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }
    TEST(ExecutorReverseFastTest, should_return_S_and_x_minus_1_given_status_is_fast_command_is_L_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        executor->Execute("FBL");

        const Pose target{-1, 0, 'S'};
        ASSERT_EQ(target, executor->Query());
    }
    TEST(ExecutorReverseFastTest, should_return_N_and_x_minus_1_given_is_fast_and_reverse_given_command_is_R_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        executor->Execute("FBR");

        const Pose target{-1, 0, 'N'};
        ASSERT_EQ(target, executor->Query());
    }
}