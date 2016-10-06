function(page) {
    var regex = /<IMG[^>]*SRC="([^"]*\/cartoons\/archives\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
