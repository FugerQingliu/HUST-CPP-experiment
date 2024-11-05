#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    /*
        Executor的具体实现
    */
    class ExecutorImpl final : public Executor
    {
    public:
        explicit ExecutorImpl(const Pose &pose) noexcept;
        ~ExecutorImpl() noexcept = default;
        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        Pose Query(void) const noexcept override;
        void Execute(const std::string &commands) noexcept override;

    private:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;

    private:
        class MoveCommand final
        {
            public:
            void DoOperate(ExecutorImpl& executor) const noexcept
            {
                executor.Move();
            } 
        };
    private:
        Pose pose;
        bool isFast;
    };
}