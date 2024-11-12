#pragma once
#include ".\ExecutorImpl.hpp"
#include ".\core\PoseHandler.hpp"
#include "CmderOrchestrator.hpp"
#include <functional>
namespace adas
{
    class MoveCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.Move(poseHandler);
        };
    };
    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.TurnLeft(poseHandler);
        };
    };
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            return orchestrator.TurnRight(poseHandler);
        };
    };
    class FastCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler,const CmderOrchestrator& orchestrator) const noexcept
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
         ActionGroup operator()(const PoseHandler &poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_REVERSE_ACTION;
            actionGroup.PushAcition(action);
            return actionGroup;
        };
    };
    class TurnRoundCommand final
    {
        public :
        ActionGroup operator()(const PoseHandler& poseHandler,const CmderOrchestrator& orchestrator) const noexcept
        {
            if(poseHandler.IsReverse())
            {
                return ActionGroup();
            }
            else
            {
                if(poseHandler.IsFast())
                {
                    return ActionGroup({
                        ActionType::FORWARD_1_STEP_ACTION,
                        ActionType::TURNLEFT_ACTION,
                        ActionType::FORWARD_1_STEP_ACTION,
                        ActionType::TURNLEFT_ACTION,
                    });
                }
                else
                {
                    return ActionGroup({
                        ActionType::TURNLEFT_ACTION,
                        ActionType::FORWARD_1_STEP_ACTION,
                        ActionType::TURNLEFT_ACTION,
                    });
                }
            }
        }
    };
}