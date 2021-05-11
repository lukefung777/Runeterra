// Copyright (c) 2021 Runeterra Team
// Chris Ohk, Seokmin Hong
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef RUNETERRA_CARDS_HPP
#define RUNETERRA_CARDS_HPP

#include <optional>

namespace Runeterra
{
//!
//! \brief Cards class.
//!
//! This class provides several search methods.
//!
class Cards
{
 public:
    //! Returns a card that matches \p code.
    //! \param code The card code to find.
    //! \return A card that matches \p code.
    //[[nodiscard]] std::optional<Card> FindCardByCode(
    //    const std::string_view& code);
};
}  // namespace Runeterra

#endif  // RUNETERRA_CARDS_HPP