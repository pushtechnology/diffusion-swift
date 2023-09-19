// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Diffusion",
    products: [
        .library(
            name: "Diffusion",
            targets: [ "Diffusion" ]
        ),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "Diffusion",
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.8.4/Diffusion.xcframework.zip",
            checksum: "e2837eb744d907b8b4bfcef52a4444990d548c9ee5c773bdcf521bc00d1f7115"
        )
    ]
)
