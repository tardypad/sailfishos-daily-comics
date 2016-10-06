function(page) {
    var regex = /<link rel="image_src" href="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
