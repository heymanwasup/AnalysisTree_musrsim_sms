import ROOT as R

scaleToLumi = True

name_map = {
    'e_m' : 'e^{-}',
    'e_p' : 'e^{+}',
    'mu_m' : '#mu^{-}',
    'mu_p' : '#mu^{+}',
    'gamma' : '#gamma',
    'compt' : 'Compton scattering',
    'eIoni' : 'Ionisation',
    'conv'  : '#gamma conversion',
    'phot' : 'Photo-electric effect',
    'initialParticle' : 'Initial particle',
    'photonNuclear' : 'Photon nucleaer',
    'neutronInelastic' : 'Neutron inelastic',
    'hadElastic' : 'Hadron elastic',
    'annihil' : 'Annihilate',
    'e_m_From_mu_m' : 'e^{-} from #mu^{-} decay',
    'e_p_From_mu_p' : 'e^{+} from #mu^{+} decay',
}

processes = [
    'DecayWithSpin',
    'eIoni',
    'eBrem',
    'annihil',
    'LowEnCompton',
    'LowEnConversion',
    'LowEnBrem',
    'LowEnergyIoni',
    'LowEnPhotoElec',
    'RadioactiveDecay',
    'muIoni',
    'MuFormation',
    'Decay',
    'conv',
    'compt',
    'phot',
    'dInelastic',
    'electronNuclear',
    'GammaToMuPair',
    'hBertiniCaptureAtRest',
    'hIoni',
    'lambdaInelastic',
    'muMinusCaptureAtRest',
    'muonNuclear',
    'nCapture',
    'neutronInelastic',
    'photonNuclear',
    'pi-Inelastic',
    'pi+Inelastic',
    'protonInelastic',
    'tInelastic',
    'hadElastic',
    'initialParticle',
]

particles = [
    "deuteron",
    "triton",
    "He3",
    "alpha",
    "Li4",
    "Li6",
    "Li7",
    "Be7",
    "Be8",
    "Be9",
    "Be10",
    "B9",
    "B10",
    "B10",
    "B11",
    "C11",
    "C12",
    "C13",
    "N13",
    "F18",
    "Ne20",
    "Ne21",
    "Ne22",
    "Na22",
    "Na23",
    "Mg24",
    "Mg25",
    "Mg25",
    "Mg26",
    "Al26",
    "Al26",
    "Al27",
    "neutron",
    "pi-",
    "pi+",
    "proton",
    "mu_m",
    "mu_p",
    "e_m",
    "e_p",
    "gamma",
]



def Sort_keys(keys,hist_tmp,f=R.TH1F.Integral):
    integrals = []
    for k in keys:
        h = GetHist(hist_tmp.format(k))
        if h!=None:
            integrals.append([k,f(h)])
    integrals.sort(key=lambda x:x[1],reverse=True)
    return integrals

def GetHist(name):
    h = tfile.Get(name)
    if h != None:
        h = h.Clone()
        if scaleToLumi:
            h.Scale(lumi_scale)
    return h

def DrawTotalDep(xRange,title,rebin=0,hist_name='Detector_edep',draw_tex=True,tex_pos=[25,1e6],scale_by_binW=False):
    hist = GetHist(hist_name)
    
    if rebin>0:
        hist.Rebin(rebin)        
    hist.SetStats(0)
    hist.SetTitle(title)
    hist.GetXaxis().SetRangeUser(xRange[0],xRange[1])
    if scale_by_binW:
        binW = hist.GetXaxis().GetBinWidth(1)
        hist.Scale(1/binW)
        

    hist.SetLineColor(1)
    hist.SetLineWidth(3)
    

    mean = hist.GetMean()
    sum_of_edep = hist.Integral() * mean # MeV
    # sum_of_edep = hist.Integral() * mean * 1.6022e-13 # From MeV to J
    c = R.TCanvas()
    c.SetLogy(1)
    hist.Draw('e')
    l = R.TLatex()
    if draw_tex:        
        energy_str = '{0:.1E}'.format(sum_of_edep).split('E')    
        l.DrawLatex(tex_pos[0],tex_pos[1],'Total energy deposits: {0:} #times 10^{{{1:}}} MeV ( 10 pC of e^{{-}} )'.format(energy_str[0],int(energy_str[1])))
        l.Draw()
        
    return c,[hist,l]

def DrawEdep(tmp_h,xRange,title,rebin=0,particles=[],legPos=[],isLogy=False,scale_by_binW=False):
    if len(legPos)==0:
        legPos = [0.6,0.45,0.9,0.9]
    hists = {}    
    color_array = [1,2,4,6,7,8,9,11,12,13,14,15,16,17]
    leg = R.TLegend(*legPos)
    c = R.TCanvas()
    maxi = 0.
    # print name_map


    for n,p in enumerate(particles):        
        hists[p] = GetHist(tmp_h.format(p))
        if rebin>0:
            hists[p].Rebin(rebin)
         
        x,y = hists[p].GetXaxis().FindBin(xRange[0]),hists[p].GetXaxis().FindBin(xRange[1])
        hists[p].GetXaxis().SetRange(x,y)
        hists[p].GetXaxis().SetRangeUser(xRange[0],xRange[1])
        if scale_by_binW:
            binW = hists[p].GetXaxis().GetBinWidth(1)
            hists[p].Scale(1/binW)
        hists[p].SetStats(0)
        hists[p].SetTitle(title)

        hists[p].SetLineColor(color_array[n])
        hists[p].SetMarkerColor(color_array[n])        
        hists[p].SetLineWidth(3)
        hists[p].SetMarkerSize(1)

        maxi_temp = hists[p].GetMaximum()

        if maxi_temp>maxi:
            maxi = maxi_temp
        entry_name = p
        # print p
        if p in name_map:
            entry_name = name_map[p]

        leg.AddEntry(hists[p],entry_name,'l')

    for p in particles:
        if isLogy:
            hists[p].SetMaximum(maxi*10)
        else:
            hists[p].SetMaximum(maxi*1.2)
        hists[p].Draw('histsame')
    leg.Draw()    
    return c,[hists,leg]