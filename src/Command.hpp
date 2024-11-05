#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

#include <functional>
namespace adas
{
    // class ICommand
    // {
    // public:
    //     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    //     virtual ~ICommand(void) = default;
    // };
    class MoveCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // const std::function<void(PoseHandler& PoseHandler)> operate = [](PoseHandler& poseHandler) noexcept
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {

                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse())
            {
                poseHandler.Backward();
            }
            else
            {
                poseHandler.Forward();
            }
        };
    };
    class TurnLeftCommand final // : public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {

                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnRight();
            }
            else
            {
                poseHandler.TurnLeft();
            }
        };
    };
    class TurnRightCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {

                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnLeft();
            }
            else
            {
                poseHandler.TurnRight();
            }
        };
    };
    class FastCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        };
    };

    class ReverseCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Reverse();
        };
    };
}