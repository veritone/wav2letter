/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "common/Defines.h"

#include <cstdlib>
#include <limits>

namespace w2l {

// DATA OPTIONS
DEFINE_string(train, "", "comma-separated list of training data");
DEFINE_string(valid, "", "comma-separated list of valid data");
DEFINE_string(test, "", "comma-separated list of test data");
DEFINE_int64(batchsize, 1, "batch size (per process in distributed training)");
DEFINE_string(input, "flac", "input feature");
DEFINE_int64(samplerate, 16000, "sample rate (Hz)");
DEFINE_int64(channels, 1, "number of input channels");
DEFINE_string(tokens, "tokens.txt", "path/to/tokens");
DEFINE_bool(usewordpiece, false, "use word piece as target");
DEFINE_int64(
    replabel,
    0,
    "replace up to replabel reptitions by additional classes");
DEFINE_string(surround, "", "surround target with provided label");
DEFINE_bool(noresample, false, "do not resample training data");
DEFINE_bool(eostoken, false, "append target with end of sentence token");
DEFINE_string(
    dataorder,
    "input",
    "bin method to use for binning samples, input: in order of length of \
    input, input_spiral: binning using transcript(reference) length , \
    and spiral along audiolength, output_spiral: binning using audio length and \
    spiral along reference lenth");
DEFINE_int64(inputbinsize, 100, "Bin size along audio length axis");
DEFINE_int64(outputbinsize, 5, "Bin size along transcript length axis");
DEFINE_bool(listdata, false, "use lists instead of folders as input data");
DEFINE_string(
    wordseparator,
    kSilToken,
    "extra word boundaries to be inserted during target generation");
DEFINE_double(
    sampletarget,
    0.0,
    "probability [0.0, 1.0] for randomly sampling targets from a lexicon if there are multiple mappings from a word");

// FILTERING OPTIONS
DEFINE_int64(minisz, 0, "min input size (in msec) allowed during training");
DEFINE_int64(
    maxisz,
    std::numeric_limits<int64_t>::max(),
    "max input size (in msec) allowed during training");
DEFINE_int64(
    maxtsz,
    std::numeric_limits<int64_t>::max(),
    "max target size allowed during training");
DEFINE_int64(mintsz, 0, "min target size allowed during training");

// NORMALIZATION OPTIONS
DEFINE_int64(localnrmlleftctx, 0, "left context size for local normalization");
DEFINE_int64(
    localnrmlrightctx,
    0,
    "right context size for local normalization");
DEFINE_string(onorm, "none", "output norm (none");
DEFINE_bool(sqnorm, false, "use square-root while normalizing criterion loss");

// LEARNING HYPER-PARAMETER OPTIONS
DEFINE_int64(iter, 1000000, "number of iterations");
DEFINE_bool(itersave, false, "save model at each iteration");
DEFINE_double(lr, 1.0, "learning rate");
DEFINE_double(momentum, 0.0, "momentum factor");
DEFINE_double(weightdecay, 0.0, "weight decay (L2 penalty)");
DEFINE_double(lrcrit, 0, "criterion learning rate");
DEFINE_double(maxgradnorm, 0, "Clip gradients at value (0 = no clipping)");
DEFINE_double(adambeta1, 0.9, "beta1 in the Adam optimizer");
DEFINE_double(adambeta2, 0.999, "beta2 in the Adam optimizer");
DEFINE_double(optimrho, 0.9, "rho in the optimizer");
DEFINE_double(optimepsilon, 1e-8, "epsilon in the optimizer");

// LR-SCHEDULER OPTIONS
DEFINE_int64(
    stepsize,
    1000000,
    "We multiply LR by gamma every stepsize epochs");
DEFINE_double(gamma, 1.0, "the LR annealing multiplier");

// OPTIMIZER OPTIONS
DEFINE_string(netoptim, kSGDoptimizer, "optimizer for the network");
DEFINE_string(critoptim, kSGDoptimizer, "optimizer for the criterion");

// MFCC OPTIONS
DEFINE_bool(mfcc, false, "use standard htk mfcc features as input");
DEFINE_bool(pow, false, "use standard power spectrum as input");
DEFINE_int64(mfcccoeffs, 13, "number of mfcc coefficients");
DEFINE_bool(mfsc, false, "use standard mfsc features as input");
DEFINE_double(melfloor, 1.0, "specify optional mel floor for mfcc/mfsc/pow");
DEFINE_int64(filterbanks, 40, "Number of mel-filter bank channels");
DEFINE_int64(devwin, 0, "Window length for delta and doubledelta derivatives");
DEFINE_int64(fftcachesize, 1, "number of cached cuFFT plans in GPU memory");

// RUN OPTIONS
DEFINE_string(datadir, "", "speech data directory");
DEFINE_string(tokensdir, "", "dictionary directory");
DEFINE_string(rundir, "", "experiment root directory");
DEFINE_string(archdir, "", "arch root directory");
DEFINE_string(flagsfile, "", "File specifying gflags");
DEFINE_string(runname, "", "name of current run");
DEFINE_int64(nthread, 1, "specify number of threads for data parallelization");
DEFINE_string(
    tag,
    "",
    "tag this experiment with a particular name (e.g. 'hypothesis1')");
DEFINE_int64(seed, 0, "Manually specify Arrayfire seed.");
DEFINE_int64(
    memstepsize,
    10 * (1 << 20),
    "Minimum allocation size in bytes per array.");
DEFINE_int64(
    reportiters,
    0,
    "number of iterations after which we will run val and save model, \
    if 0 we only do this at end of epoch ");
DEFINE_double(
    pcttraineval,
    100,
    "percentage of training set (by number of utts) to use for evaluation");

DEFINE_int64(runtimeLayer, 0, "layer to run NN to for feature extration");

// ARCHITECTURE OPTIONS
DEFINE_string(arch, "default", "network architecture");
DEFINE_string(criterion, kAsgCriterion, "training criterion");
DEFINE_int64(encoderdim, 0, "Dimension of encoded hidden state.");

// DECODER OPTIONS

DEFINE_bool(show, false, "show predictions");
DEFINE_bool(showletters, false, "show letter predictions");
DEFINE_bool(logadd, false, "use logadd when merging decoder nodes");

DEFINE_string(smearing, "none", "none, max or logadd");
DEFINE_string(lmtype, "kenlm", "kenlm, convlm");
DEFINE_string(lexicon, "", "path/to/lexicon.txt");
DEFINE_string(lm_vocab, "", "path/to/lm_vocab.txt");
DEFINE_string(emission_dir, "", "path/to/emission_dir/");
DEFINE_string(lm, "", "path/to/language_model");
DEFINE_string(am, "", "path/to/acoustic_model");
DEFINE_string(sclite, "", "path/to/sclite to be written");
DEFINE_string(decodertype, "wrd", "wrd, tkn");

DEFINE_double(lmweight, 1.0, "language model weight");
DEFINE_double(wordscore, 1.0, "wordscore");
DEFINE_double(silweight, 0.0, "silence weight");
DEFINE_double(
    unkweight,
    -std::numeric_limits<float>::infinity(),
    "unknown word weight");
DEFINE_double(beamthreshold, 25, "beam score threshold");

DEFINE_int32(maxload, -1, "max number of testing examples.");
DEFINE_int32(maxword, -1, "maximum number of words to use");
DEFINE_int32(beamsize, 2500, "max beam size");
DEFINE_int32(nthread_decoder, 1, "number of threads for decoding");
DEFINE_int32(
    lm_memory,
    5000,
    "total memory size for batch during forward pass ");

DEFINE_double(
    smoothingtemperature,
    1.0,
    "smoothening the probability distribution in seq2seq decoder");
DEFINE_int32(
    attentionthreshold,
    std::numeric_limits<int>::infinity(),
    "hard attention limit");
DEFINE_double(hardselection, 1.0, "end-of-sentence threshold");
DEFINE_double(
    softselection,
    std::numeric_limits<double>::infinity(),
    "threshold to keep new candidate from being proposed");

// ASG OPTIONS
DEFINE_int64(linseg, 0, "# of epochs of LinSeg to init transitions for ASG");
DEFINE_double(linlr, -1.0, "LinSeg learning rate (if < 0, use lr)");
DEFINE_double(
    linlrcrit,
    -1.0,
    "LinSeg criterion learning rate (if < 0, use lrcrit)");
DEFINE_double(
    transdiag,
    0.0,
    "Initial value along diagonal of ASG transition matrix");

// SEQ2SEQ OPTIONS
DEFINE_int64(maxdecoderoutputlen, 200, "max decoder steps during inference");
DEFINE_int64(
    pctteacherforcing,
    100,
    "Percentage of steps to train using teacher forcing");
DEFINE_string(
    samplingstrategy,
    "rand",
    "Sampling strategy to use when pctteacherforcing < 100. rand or model");
DEFINE_double(
    labelsmooth,
    0.0,
    "Fraction to smooth targets with uniform distribution.");
DEFINE_bool(inputfeeding, false, "feed encoder summary to the decoder RNN");
DEFINE_string(attention, "content", "attention type");
DEFINE_string(attnWindow, "no", "attention window type");
DEFINE_int64(attndim, 0, "Dimension of neural location attention");
DEFINE_int64(
    attnconvchannel,
    0,
    "Number of convolutional channels for location attention");
DEFINE_int64(attnconvkernel, 0, "Kernel width for location attention");
DEFINE_int64(leftWindowSize, 50, "left median window width");
DEFINE_int64(rightWindowSize, 50, "right median window width");
DEFINE_int64(
    maxsil,
    50,
    "maximum number of leading silence frames for the step window");
DEFINE_int64(
    minsil,
    0,
    "minimum number of leading silence frames for the step window");
DEFINE_double(
    maxrate,
    10,
    "maximum ratio between the transcript and the encoded input lengths for the step window");
DEFINE_double(
    minrate,
    3,
    "minimum ratio between the transcript and the encoded input lengths for the step window");
DEFINE_int64(
    softwoffset,
    10,
    "offset for the soft window center (= offset + step * rate)");
DEFINE_double(
    softwrate,
    5,
    "moving rate for the soft window center (= offset + step * rate)");
DEFINE_double(
    softwstd,
    5,
    "std for the soft window shape (=exp(-(t - center)^2 / (2 * std^2)))");
DEFINE_bool(trainWithWindow, false, "use window in training");
DEFINE_int64(
    pretrainWindow,
    0,
    "use window in training for pretrainWindow epochs");
DEFINE_double(gumbeltemperature, 1.0, "temperature in gumbel softmax");

// DISTRIBUTED TRAINING
DEFINE_bool(enable_distributed, false, "enable distributed training");
DEFINE_int64(
    world_rank,
    0,
    "rank of the process (Used if rndv_filepath is not empty)");
DEFINE_int64(
    world_size,
    1,
    "total number of the process (Used if rndv_filepath is not empty)");
DEFINE_string(
    rndv_filepath,
    "",
    "Shared file path used for setting up rendezvous."
    "If empty, uses MPI to initialize.");

// FB SPECIFIC
DEFINE_string(target, "tkn", "target feature");
DEFINE_bool(everstoredb, false, "use Everstore db for reading data");
} // namespace w2l
