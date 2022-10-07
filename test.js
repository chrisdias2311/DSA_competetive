

import React from 'react';
import { Grid, Typography, Button } from '@material-ui/core';
import { NoAds } from '../../components/Widgets/Dashboard/Messages';
import AdItem from '../../components/Widgets/Ads/AdItemWide/AdItem'
import Filters from '../../components/Widgets/Filters/Filters';
import CategoryHeader from '../../components/Widgets/Category/Header';
import Sidebar from '../../components/Widgets/Category/Sidebar/Sidebar'
import Paginate from '../../components/Widgets/Category/Paginate/Paginate'
import SaveWidget from '../../components/Widgets/Favorites/Save/Save';
import router from 'next/router';
import Icon from '@mdi/react';
import { MakeBreads } from '../../components/Helpers/SEO/GoogleReach';
import Head from 'next/head';
import VizSensor from 'react-visibility-sensor'
import Loader from '../../components/UI/Element/Loader/Linear';
import config from '../../components/Helpers/Config'
import Css from './Css.css';

import {
    mdiClose,
    mdiFilterOutline
} from '@mdi/js';

// redux part
import * as actions from '../../redux/actions';
import { connect } from 'react-redux';

class Category extends React.Component {

    state = {
        saveId: null,
        breads: []
    }

    makeHeads(section, category, canonical) {
        const data = {
            title: {
                main: 'Chicago Classified Ads | FMC',
                section: '{cat} in Chicago, IL | FMC',
                category: '{cat} for Sale in Chicago, IL | FMC'
            },
            description: {
                main: 'Chicago Classified Ads. Browse all classified ads in Chicago, IL. Find what you are looking for or create your own ad for free!',
                section: '{cat} in Chicago, IL. Find what you are looking for or create your own ad for free!',
                category: '{cat} for Sale in Chicago, IL. Find what you are looking for or create your own ad for free!'
            }
        }

        // set default as all/all
        let title = data.title.main, description = data.description.main

        if (section) {
            if (category) {
                title = data.title.category.replace('{cat}', category.name)
                description = data.description.category.replace('{cat}', category.name)
            } else {
                title = data.title.section.replace('{cat}', section.name)
                description = data.description.section.replace('{cat}', section.name)
            }
        }

        return (
            <Head>
                <title>{title}</title>
                <meta name='description' content={description} />
                <link rel='canonical' href={canonical} />
            </Head>
        )
    }

    paginateAds = () => {
        if (this.props.ads.content.ads[this.props.ads.content.ads] && this.props.ads.content.ads[this.props.ads.content.ads].length < 15) {
            console.log('skil.as.no.more')
            return
        }

        if (!this.props.ads.loading) {
            const params = { page: this.props.ads.filter.page + 1 }
            this.props.setFilters(params)
            this.props.getAds({ ...this.props.ads.filter, ...params })
        } else {
            console.log('CP.loading...')
        }
        // scroll to the top
        // if(window) window.scrollTo(0,0)
    }

    componentDidMount() {
        this.props.getFavs(null, this.props.auth.user)
        const body = document.querySelector('body')
        body.dataset.section = this.props.ads.filter.section
    }

    showSave = (id) => {
        this.setState({ saveId: id })
    }

    showTopAds = () => {
        let url = '/category/' + this.props.ads.filter.section + '/' + this.props.ads.filter.category
        let params = this.props.ads.filter
        router.push({ pathname: url, query: { feature: 'topad' } })
    }

    cleanFeature = () => {
        let url = '/category/' + this.props.ads.filter.section + '/' + this.props.ads.filter.category
        router.push({ pathname: url })
    }

    render() {
        // feature name
        const feature = this.props.static.feature[this.props.ads.filter.feature]
        const mainTitle = feature ? feature.name : 'All Ads'
        const loader = this.props.ads.loading ? <Loader className={Css.Loader} /> : '';

        // const hasContent = this.props.ads.content.ads[this.props.ads.filter.page] && this.props.ads.content.ads[this.props.ads.filter.page].length
        let filterIcoClass = [Css.SidebarIcon]
        let sidebarClass = [Css.Sidebar]
        let contentClass = [Css.Content]

        if (this.props.design.show_sidebar) {
            sidebarClass.push(Css.SidebarOpen)
            contentClass.push(Css.HideContent)
        }

        // build breads for google reach results
        const breads = []
        let canonical = config.client + 'category/'

        if (this.props.query.section_id != 'all') {
            const cat = Object.values(this.props.static.category).filter(cat => cat.slug == this.props.query.section_id)
            if (cat && cat.length) breads.push(cat[0])

            if (this.props.query.category_id != 'all') {
                const cat = Object.values(this.props.static.category).filter(cat => cat.slug == this.props.query.category_id)
                if (cat && cat.length) breads.push(cat[0])
            }
        }

        canonical += breads[0] ? (breads[0].slug + '/' + (breads[1] ? breads[1].slug : 'all')) : 'all/all'

        const heads = this.makeHeads(breads[0], breads[1], canonical)

        const saveModal = this.state.saveId
            ? <SaveWidget
                open={true}
                setOpen={() => this.showSave(false)}
                ad_id={this.state.saveId}
                userId={this.props.auth.user ? this.props.auth.user.id : null}
            />
            : ''

        // const paginate = hasContent || this.props.ads.filter.page > 1 
        //   ? (<Paginate
        //       query={this.props.query}
        //       filters={this.props.ads.filter}
        //       static={this.props.static}
        //       page={this.props.ads.filter.page}
        //       paginateStep={this.props.ads.paginateStep}
        //       filter={this.paginateAds}
        //       hasMore={this.props.ads.content.ads.length >= this.props.ads.itemsPerPage}
        //     />)
        //   : ''

        // base ads list
        let adsContent = []

        Object.keys(this.props.ads.content.ads).map(item => {
            this.props.ads.content.ads[item].map(ad => {
                adsContent.push(<AdItem
                    hideCatLink={true}
                    device={this.props.device.deviceType}
                    saved={this.props.favorites.ads[ad.id]}
                    post={ad}
                    noMessage={true}
                    showSave={this.showSave} />)
            })
        })

        // console.log('TOPADS:', this.props.ads.content.topAds)

        // top ads list - display only first pagination, will change later
        let topAdsContent = []

        this.props.ads.content.topAds[1] ? this.props.ads.content.topAds[1].map((ad) => {
            topAdsContent.push(<AdItem
                hideCatLink={true}
                device={this.props.device.deviceType}
                topAd={true}
                saved={this.props.favorites.ads[ad.id]}
                post={ad}
                noMessage={true}
                showSave={this.showSave}
            />)
        }) : ''

        const topAdsNav = topAdsContent.length ? (
            <div className={Css.TopAdsFooter}>
                <Button onClick={this.showTopAds} className={Css.TopAdsLink} color="primary">View All Top Ads</Button>
            </div>
        ) : ''

        return (
            <Grid container spacing={3} className={Css.Container} id={"cat_section_" + breads && breads[0] ? breads[0].slug : ''}>
                {/* SEO */}
                {heads}

                {saveModal}

                <Grid item xl={12} lg={12} md={12} sm={12} xs={12} className={Css.Header}>
                    <CategoryHeader {...this.props} />
                </Grid>

                {/*   
        <Helmet>
            <link rel="stylesheet" href="/static/css/countdown.css" />
        </Helmet> */}

                {breads.length > 0 ? <MakeBreads list={breads} /> : ''}

                {/* sidebar icon for mobile */}
                {/* <Hidden xsDown> */}
                <div className={filterIcoClass.join(' ')} onClick={() => this.props.switchDesign('show_sidebar')}>
                    <Icon path={this.props.design.show_sidebar ? mdiClose : mdiFilterOutline} size={1} color='#5c6bc0' className={Css.FilterIcon} />
                </div>
                {/* </Hidden> */}

                {/* Category Sidebar */}
                <Grid item xl={3} lg={3} md={3} sm={3} xs={12} className={sidebarClass.join(' ')}>
                    <Sidebar {...this.props} feature={feature} cleanFeature={this.cleanFeature} />
                </Grid>

                {/* Category Content */}
                <Grid item xl={9} lg={9} md={9} sm={9} xs={12} className={contentClass.join(' ')}>

                    {/* ads sorting filters */}
                    <Filters
                        filter={this.props.ads.filter}
                        setFilters={this.props.setFilters}
                        filterAds={this.props.filterAds}
                    />

                    {/* Sign Up Message */}
                    {/* <MotivateAuth /> */}

                    {/* Ads List */}
                    <Grid container spacing={3} className={Css.Ads}>
                        {topAdsContent && topAdsContent.length
                            ? <Typography className={Css.Adh6} variant='h1'>
                                {this.props.query.category_id != 'all'
                                    ? this.props.query.category_id.split('-').join(' ')
                                    : 'All ads in ' + this.props.query.section_id.split('-').join(' ')}
                            </Typography>
                            : ''}
                        {topAdsContent}
                        {topAdsNav}

                        <Typography className={Css.Adh6} variant='h5'>
                            {/* {mainTitle} */}
                            {/* if featured ads - display get back to normal ads button */}
                            {feature ? <Button className={Css.BackBtn} color='primary' size='small' onClick={this.cleanFeature}>Back to Ads</Button> : ''}
                        </Typography>

                        {adsContent.length ? adsContent : <NoAds url={'/items/create?category=' + this.props.query.category_id} />}
                    </Grid>

                    {/* {paginate} */}

                    {loader}

                    {/* infinite scrolling */}
                    <VizSensor
                        partialVisibility
                        onChange={(isVisible) => {
                            if (isVisible) {
                                this.paginateAds()
                            }
                        }}>
                        <div style={{ width: '100%', height: '2px' }}></div>
                    </VizSensor>

                </Grid>

            </Grid>
        );
    }
}

const mapStateToProps = state => {
    return {
        auth: state.auth,
        ads: state.ads,
        favorites: state.favorites.content,
        static: state.static,
        design: state.design.design
    }
}

const mapDispatchToProps = dispatch => {
    return {
        getAds: (props, req = null) => dispatch(actions.getAds(props, req)),
        getFavs: (req, user) => dispatch(actions.fetchFavLists(req, user)),
        setFilters: (vals) => dispatch(actions.setFilters(vals)),
        resetFilters: () => dispatch(actions.resetFilters()),
        filterAds: (props) => dispatch(actions.filterAds(props)),
        switchDesign: (item) => dispatch(actions.switchDesign(item))
    }
}

export default connect(mapStateToProps, mapDispatchToProps)(Category)






// ??hello world 
