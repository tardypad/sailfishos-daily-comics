function(page) {
    var regex = /<link[^>]* as="image"[^>]* href="(https?:\/\/static\.explosm\.net\/20[2-9][0-9]\/[01][0-9]\/[0-9]+\/[-+._0-9A-Za-z]+\.[-+_0-9A-Za-z]+)"\/>/;
    var match = regex.exec(page);
    return match[1];
}
