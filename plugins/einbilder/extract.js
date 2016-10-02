function(page) {
    var regex = /<img[^>]*src="(images\/cartoons\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
