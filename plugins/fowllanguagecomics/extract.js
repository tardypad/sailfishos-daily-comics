function(page) {
    var regex = /<meta property="og:image" content="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
