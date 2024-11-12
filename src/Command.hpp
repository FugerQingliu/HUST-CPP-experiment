#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"
#include "ActionGroup.hpp"
#include <functional>
namespace adas
{
    class MoveCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse() ?
                ActionType::BACKWARD_1_STEP_ACTION:
                ActionType::FORWARD_1_STEP_ACTION;
            if(poseHandler.IsFast())
            {
                actionGroup.PushAcition(action);
            }
            actionGroup.PushAcition(action);
            return actionGroup;
        };
    };
    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse() ?
                ActionType::REVERSE_TURNLEFT_ACTION:
                ActionType::TURNLEFT_ACTION;
            if(poseHandler.IsFast())
            {
                actionGroup.PushAcition(poseHandler.IsReverse()?
                ActionType::BACKWARD_1_STEP_ACTION:
                ActionType::FORWARD_1_STEP_ACTION
                );
            }
            actionGroup.PushAcition(action);
            return actionGroup;
        };
    };
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse() ?
                ActionType::REVERSE_TURNRIGHT_ACTION:
                ActionType::TURNRIGHT_ACTION;
            if(poseHandler.IsFast())
            {
                actionGroup.PushAcition(poseHandler.IsReverse()?
                ActionType::BACKWARD_1_STEP_ACTION:
                ActionType::FORWARD_1_STEP_ACTION
                );
            }
            actionGroup.PushAcition(action);
            return actionGroup;
        };
    };
    class FastCommand final //: public ICommand
    {
    public:
       ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_FAST_ACTION;
            actionGroup.PushAcition(action);
            return actionGroup;
        };
    };

    class ReverseCommand final //: public ICommand
    {
    public:
         ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_REVERSE_ACTION;
            actionGroup.PushAcition(action);
            return actionGroup;
        };
    };
}