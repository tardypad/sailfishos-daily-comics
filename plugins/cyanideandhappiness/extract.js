function(page) {
    var regex = /<link rel="preload" as="image" href="(https:\/\/static.explosm.net\/20[2-9][0-9]\/[0-1][0-9]\/[0-9]+\/[a-z]+.png)"\/>/;
    var match = regex.exec(page);
    return match[1];

