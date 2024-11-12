#pragma once
#include "CmderOrchestrator.hpp"

namespace adas
{
    class NormalOrchestrator : public CmderOrchestrator
    {
        ActionGroup Move(const PoseHandler& poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAcition(GetStepAction(poseHandler));
            return actionGroup;
        }
        ActionGroup TurnLeft(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            if(poseHandler.IsReverse())
                actionGroup.PushAcition(ActionType::TURNRIGHT_ACTION);
            else
                actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            return actionGroup;
        }
        ActionGroup TurnRight(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            if(poseHandler.IsReverse())
                actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            else
                actionGroup.PushAcition(ActionType::TURNRIGHT_ACTION);
            return actionGroup;
        }
        ActionGroup TurnRound(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            if(poseHandler.IsReverse())
                return ActionGroup();
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            actionGroup.PushAcition(ActionType::FORWARD_1_STEP_ACTION);
            actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            return actionGroup;
        }
        protected:
        ActionType GetStepAction(const PoseHandler& poseHandler) const noexcept
        {
            return poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        }
        ActionGroup OnFast(const PoseHandler& poseHandler) const noexcept
        {
            if(poseHandler.IsFast())
            {
                return ActionGroup({GetStepAction(poseHandler)});
            }
            return ActionGroup();
        }
    };
}