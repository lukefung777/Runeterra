// Copyright (c) 2021 Runeterra Team
// Chris Ohk, Dongyeon Park, Seungwon Seo
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef RUNETERRA_CARD_ENUMS_HPP
#define RUNETERRA_CARD_ENUMS_HPP

namespace Runeterra
{
//! \brief An enumerator for identifying the type of the card.
enum class CardType
{
    INVALID,
    UNIT,
    SPELL,
    ABILITY,
    LANDMARK,
};
}  // namespace Runeterra

#endif  // RUNETERRA_CARD_ENUMS_HPP
