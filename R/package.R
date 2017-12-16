
#' R's Internal 'tar' Implementation as a Package
#'
#' There have been various issues with R's builtin 'tar' implementation
#' recently. This packages contains a version that fixes several of these
#' issues, so we can have a stable implementation that works with any R
#' version.
#'
#' @docType package
#' @useDynLib tar, .registration = TRUE, .fixes = "C_"
#' @name tar
NULL
