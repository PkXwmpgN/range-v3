/// \file
// Range v3 library
//
//  Copyright Eric Niebler 2013-present
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/range-v3
//

#ifndef RANGES_V3_UTILITY_DANGLING_HPP
#define RANGES_V3_UTILITY_DANGLING_HPP

#include <utility>
#include <concepts/concepts.hpp>
#include <range/v3/range_fwd.hpp>
#include <range/v3/utility/static_const.hpp>

namespace ranges
{
    inline namespace v3
    {
        /// \ingroup group-core
        /// A wrapper for an iterator or a sentinel into a range that may
        /// no longer be valid.
        struct dangling
        {
            dangling() = default;
            /// Implicit converting constructor; ignores argument
            template<typename T>
            constexpr CPP_ctor(dangling)(T &&)(
                requires NotSameAs_<T, dangling>)
            {}
        };

        /// \cond
        struct _sanitize_fn
        {
            template<typename T>
            constexpr T &&operator()(T &&t) const noexcept
            {
                return static_cast<T &&>(t);
            }
        };

        using sanitize_fn RANGES_DEPRECATED("The sanitize function is unneeded and deprecated.") =
            _sanitize_fn;

        inline namespace
        {
            RANGES_DEPRECATED("The sanitize function is unneeded and deprecated.")
            constexpr auto &sanitize = static_const<_sanitize_fn>::value;
        }
        /// \endcond
    }
}

#endif
