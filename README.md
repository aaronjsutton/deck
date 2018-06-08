![Deck](assets.xcassets/Logo.imageset/Logo@2x.png)

Deck is a library that models and manipulates a
simulated deck of cards.  

# Getting Started
Read the [Quick Start Guide](https://github.com/aaronjsutton/deck/wiki/Deck-Quick-Start-Guide) to learn how to use Deck.

## Documentation
For detailed usage, read the [API Documentation](https://docs.aaronjsutton.com/deck)

# Testing

Testing can be done in one of two ways. Manually on any system, or in Xcode on macOS.

First, ensure submodules are up-to-date with:
```
git submodule update --init
```

## Xcode
### macOS

Unit tests can be invoked directly from Xcode using the test feature.
For more information, see [Apple's documentation](https://developer.apple.com/documentation/xctest)

## Manual
### Linux, macOS

Deck uses the testing framework [µnit](https://nemequ.github.io/munit/).
As µnit is part of the repository, running the tests is very simple.

Then, the tests can be invoked from `make` using:
```
make test
```

# Frequently Asked
> **Q:** _Why would I need Deck?_

**A:** Because who doesn't enjoy poker night?
