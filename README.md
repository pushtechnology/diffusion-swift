
<img src="https://docs.pushtechnology.com/docs/6.11.0/manual/html/lib/img/logos/push-new.png" style="width:250px;"/>

<p/>

<p>
    <img src="https://img.shields.io/badge/Swift-5+-F06C33.svg" />
    <img src="https://img.shields.io/badge/iOS-15.0+-865EFC.svg" />
    <img src="https://img.shields.io/badge/iPadOS-15.0+-F65EFC.svg" />
    <img src="https://img.shields.io/badge/macOS-10.15+-179AC8.svg" />
    <img src="https://img.shields.io/badge/tvOS-15.0+-41465B.svg" />
    <a href="https://github.com/apple/swift-package-manager">
      <img src="https://img.shields.io/badge/spm-compatible-brightgreen.svg?style=flat" />
    </a>
</p>


<p align="center">


# Apple SDK for Diffusion - Swift Package

#### Latest version: 6.11.0

#### Links
- <a href="https://docs.pushtechnology.com/quickstart">Quick Start Guide</a>
- <a href="https://docs.pushtechnology.com/docs/6.11.0/manual/html/developerguide/developerguide_overview.html">Developer Guide</a>
- <a href="https://docs.pushtechnology.com/docs/6.11.0/apple">API Documentation</a>
- <a href="https://github.com/pushtechnology/diffusion-examples/tree/6.11/apple">Examples</a>


## Installation

### Xcode Projects

Select `File` -> `Swift Packages` -> `Add Package Dependency` and enter `https://github.com/pushtechnology/diffusion-swift`.


### Swift Package Manager Projects

You can add `Diffusion` as a package dependency in your `Package.swift` file:

```swift
let package = Package(
    //...
    dependencies: [
        .package(
            name: "Diffusion",
            url: "https://github.com/pushtechnology/diffusion-swift",
            .exact("6.11.0")
        ),
    ],
    //...
)
```

Then simply `import Diffusion` wherever you’d like to use it.


### Requirements

- Xcode 15.1+
