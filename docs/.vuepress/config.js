module.exports = {
  base: "/Linuxduino/",
  title: "Linuxduino 0.2.0",
  port: "8085",
  description: "Linuxduino documentation",
  themeConfig: {
    // Assumes GitHub. Can also be a full GitLab url.
    repo: "NVSL/Linuxduino",
    // if your docs are not at the root of the repo:
    docsDir: "docs",
    // if your docs are in a specific branch (defaults to 'master'):
    docsBranch: "master",
    // defaults to true, set to false to disable
    editLinks: true,
    // custom text for edit link. Defaults to "Edit this page"
    logo: "",
    nav: [{ text: "Documentation", link: "/start/" }],
    sidebar: [
      {
        title: "Getting Started",
        collapsable: false,
        path: "/start/",
        children: [
          // "/development/",
          // "/development/contributing",
          // "/development/whyVuesax"
        ]
      },
      {
        title: "Reference",
        path: "/reference/",
        collapsable: false,
        children: []
      },
      {
        title: "Constants and Data Types",
        path: "/constantsAndTypes/",
        collapsable: false,
        children: []
      },
      {
        title: "GPIO",
        collapsable: false,
        children: ["/gpio/pinMode", "/gpio/digitalWrite", "/gpio/digitalRead"]
      },
      {
        title: "Serial",
        collapsable: false,
        children: [
          "/serial/find",
          "/serial/findUntil",
          "/serial/flush",
          "/serial/getset",
          "/serial/parse",
          "/serial/print",
          "/serial/write",
          "/serial/read",
          "/serial/readBytes",
          "/serial/readBytesUntil",
          "/serial/readString",
          "/serial/readStringCommand",
          "/serial/readStringUntil"
        ]
      },
      {
        title: "I2C (Wire)",
        collapsable: false,
        children: ["/i2c/getset", "/i2c/read", "/i2c/write"]
      },
      {
        title: "SPI",
        collapsable: false,
        children: [
          "/spi/getset",
          "/spi/beginTransaction",
          "/spi/setSettings",
          "/spi/transfer"
        ]
      },
      {
        title: "Time",
        path: "/time/",
        collapsable: false
      },
      {
        title: "Math",
        path: "/math/",
        collapsable: false,
        children: []
      },
      {
        title: "Trigonometry",
        path: "/trigonometry/",
        collapsable: false,
        children: []
      },
      {
        title: "Characters",
        path: "/characters/",
        collapsable: false,
        children: []
      },
      {
        title: "Random Numbers",
        path: "/randomNumbers/",
        collapsable: false,
        children: []
      },
      {
        title: "Bits and Bytes",
        path: "/bitsandbytes/",
        collapsable: false,
        children: []
      }
    ]
  }
};
