// Copyright (c) 2021 Runeterra Team
// Chris Ohk, Dongyeon Park, Seungwon Seo
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Runeterra/Games/Game.hpp>
#include <Runeterra/Games/GameManager.hpp>

namespace Runeterra
{
Game::Game(const GameConfig& config)
    : m_gameConfig{ config },
      m_players{ PlayerType::Player1, PlayerType::Player2 }
{
    // Do nothing
}

void Game::Start()
{
    // Set next step
    nextStep = Step::BeginFirst;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::ProcessUntil(Step untilStep)
{
    while (nextStep != untilStep)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::Process(Player& player, ITask&& task) const
{
    Task::Run(const_cast<Game&>(*this), player, std::move(task));
}

int Game::GetCurRound() const
{
    return m_round;
}

Player& Game::GetCurPlayer()
{
    if (m_curPlayer == PlayerType::Player1)
    {
        return m_players[0];
    }

    return m_players[1];
}

Player& Game::GetOpPlayer()
{
    if (m_curPlayer == PlayerType::Player1)
    {
        return m_players[1];
    }

    return m_players[0];
}

void Game::BeginFirst()
{
    // Set first round
    m_round = 1;

    // Set next step
    nextStep = Step::BeginShuffle;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::BeginShuffle()
{
    // Set next step
    nextStep = Step::BeginDraw;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::BeginDraw()
{
    // Set next step
    nextStep =
        m_gameConfig.skipMulligan ? Step::MainBegin : Step::BeginMulligan;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::BeginMulligan()
{
    // Do nothing
}

void Game::MainBegin()
{
    // Set next step
    nextStep = Step::MainReady;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainReady()
{
    // Set next step
    nextStep = Step::MainStartTriggers;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainStartTriggers()
{
    // Set next step
    nextStep = Step::MainResource;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainResource()
{
    // Set next step
    nextStep = Step::MainDraw;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainDraw()
{
    // Set next step
    nextStep = Step::MainStart;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainStart()
{
    // Set next step
    nextStep = Step::MainAction;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainAction()
{
    // Do nothing
}

void Game::MainEnd()
{
    // Set next step
    nextStep = Step::MainCleanUp;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainCleanUp()
{
    // Set next step
    nextStep = Step::MainNext;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::MainNext()
{
    // Set player for next round
    m_curPlayer = (m_curPlayer == PlayerType::Player1) ? PlayerType::Player2
                                                       : PlayerType::Player1;

    // Increase the number of round
    ++m_round;

    // Set next step
    nextStep = Step::MainReady;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::FinalWrapUp()
{
    // Set next step
    nextStep = Step::FinalGameOver;
    if (m_gameConfig.autoRun)
    {
        GameManager::ProcessNextStep(*this, nextStep);
    }
}

void Game::FinalGameOver()
{
    // Do nothing
}
}  // namespace Runeterra